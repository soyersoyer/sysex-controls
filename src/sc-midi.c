#include <stdio.h>

#include "sc-midi.h"

#define DESIRED_CAPS (SND_SEQ_PORT_CAP_READ | SND_SEQ_PORT_CAP_SUBS_READ | \
                      SND_SEQ_PORT_CAP_WRITE | SND_SEQ_PORT_CAP_SUBS_WRITE)

#define SYSEX_BUFFER_SIZE 2048

#define READ_TIMEOUT_MS 1000

#define AKAI_MANUF_ID 0x47

#define AKAI_RECV 0x00
#define AKAI_SEND 0x7f

#define min(a,b)             \
({                           \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a < _b ? _a : _b;       \
})

// ALSA sequencer has a maximum buffer size for MIDI SysEx
// events of 256 bytes. We need to concatenate them.
static int sc_midi_read_sysex(snd_seq_t *seq, uint8_t *sysex, unsigned int *sysex_len)
{
  snd_seq_event_t *seq_ev;

  while (1)
  {
    uint8_t *input;
    unsigned int len;

    int ret = snd_seq_event_input (seq, &seq_ev);

    if (ret < 0)
      return ret;

    input = seq_ev->data.ext.ptr;
    len = seq_ev->data.ext.len;

    if (*sysex_len + len > SYSEX_BUFFER_SIZE)
      return -EMSGSIZE;

    memcpy (sysex + *sysex_len, input, len);
    *sysex_len += len;

    if (input[len - 1] == 0xF7) break;
  }

  return 0;
}

int
sc_midi_akai_dummy_read_program (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t query_cmd, uint8_t recv_cmd, uint8_t prog_id, uint8_t *data, uint16_t *size)
{
  fprintf(stderr, "%s(%02x, %02x, %02x, %02x, %02x, %02x)\n", __func__, dev_id, query_cmd, recv_cmd, prog_id, data[0], *size);
  return 0;
}

int
sc_midi_akai_dummy_write_program (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t send_cmd, uint8_t prog_id, uint8_t *data, uint16_t size)
{
  fprintf(stderr, "%s(%02x, %02x, %02x, %02x, %02x)\n", __func__, dev_id, send_cmd, prog_id, data[0], size);
  return 0;
}

int
sc_midi_akai_dummy_select_program (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t sel_cmd, uint8_t prog_id)
{
  fprintf(stderr, "%s(%02x, %02x, %02x)\n", __func__, dev_id, sel_cmd, prog_id);
  return 0;
}

int
sc_midi_akai_read_program (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t query_cmd, uint8_t recv_cmd, uint8_t prog_id, uint8_t *data, uint16_t *size)
{
  uint8_t req_data[] = {0xf0, AKAI_MANUF_ID, AKAI_SEND, dev_id, query_cmd, 0x00, 0x01, prog_id, 0xf7};
  struct pollfd pfds[1] = {};
  snd_seq_event_t ev;
  int err, pfds_n = 0;

  uint8_t sysex[SYSEX_BUFFER_SIZE];
  unsigned int sysex_len = 0;

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, sizeof req_data, req_data);

  err = snd_seq_event_output (seq, &ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%02x): snd_seq_event_output failed %d\n", __func__, prog_id, err);
    return err;
  }

  err = snd_seq_drain_output(seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%02x): snd_seq_drain_output failed %d\n", __func__, prog_id, err);
    return err;
  }


  pfds_n = snd_seq_poll_descriptors(seq, pfds, 1, POLLIN);

  while (1)
  {
    if (snd_seq_event_input_pending (seq, 0) == 0)
    {
      err = poll (pfds, pfds_n, READ_TIMEOUT_MS);
      if (err < 0)
      {
        fprintf (stderr, "%s(%02x) poll failed %d\n", __func__, prog_id, err);
        return err;
      }
      if (err == 0)
      {
        fprintf (stderr, "%s(%02x) poll timeout %d\n", __func__, prog_id, err);
        return -ETIMEDOUT;
      }
    }

    while (1)
    {
      uint8_t akai_prog[] = {0xf0, AKAI_MANUF_ID, AKAI_RECV, dev_id, recv_cmd};

      err = sc_midi_read_sysex (seq, sysex, &sysex_len);

      if (err == -EAGAIN)
        break;

      if (err < 0) {
        fprintf (stderr, "%s(%02x) sc_midi_read_sysex failed %d\n", __func__, prog_id, err);
        return err;
      }

      if (sysex_len >= sizeof akai_prog + 3 + 1 &&
          memcmp (sysex, akai_prog, 2) == 0 &&
          // do not check AKAI_RECV or AKAI_SEND because we do not know all the details yet
          memcmp (sysex + 3, akai_prog + 3, 2) == 0 &&
          sysex[sizeof akai_prog + 2] == prog_id)
      {
        unsigned int payload_size = sysex_len - sizeof akai_prog - 3 - 1;
        if (*size < payload_size) {
          fprintf (stderr, "%s(%02x): buffer too short %d < %d\n", __func__, prog_id, *size, payload_size);
          return -EINVAL;
        }

        memcpy (data, sysex + sizeof akai_prog + 3, payload_size);
        *size = payload_size;

        fprintf (stderr, "%s(%02x): program received: size %d \n", __func__, prog_id, payload_size);

        return 0;
      }
      else
      {
        fprintf (stderr, "%s(%02x): unexpected message: len %d: ", __func__, prog_id, sysex_len);
        for (int i=0; i < sysex_len; ++i)
          fprintf(stderr, "%02x ", (uint8_t)sysex[i]);
        fprintf(stderr, "\n");
      }

    }
  }
  return 0;
}

int
sc_midi_akai_write_program (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t send_cmd, uint8_t prog_id, uint8_t *data, uint16_t size)
{
  uint8_t req_data[1024] = {0xf0, AKAI_MANUF_ID, AKAI_SEND, dev_id, send_cmd, 0x00, 0x00, prog_id};

  snd_seq_event_t ev;
  int err;

  uint16_t wsize = size + 1;

  req_data[5] = (wsize >> 7) & 0x7f;
  req_data[6] = wsize & 0x7f;

  if (size > 1024 - 9)
    return -EINVAL;

  memcpy (&req_data[8], data, size);
  req_data[8 + size] = 0xf7;

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, 8 + size + 1, req_data);

  fprintf (stderr, "%s(%02x) %d\n", __func__, prog_id, size);

  err = snd_seq_event_output (seq, &ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%02x): snd_seq_event_output failed %d\n", __func__, prog_id, err);
    return err;
  }

  err = snd_seq_drain_output(seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%02x): snd_seq_drain_output failed %d\n", __func__, prog_id, err);
    return err;
  }

  return 0;
}

int
sc_midi_akai_select_program (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t sel_cmd, uint8_t prog_id)
{
  uint8_t req_data[] = {0xf0, AKAI_MANUF_ID, AKAI_SEND, dev_id, sel_cmd, 0x00, 0x01, prog_id, 0xf7};

  snd_seq_event_t ev;
  int err;

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, sizeof req_data, req_data);

  fprintf (stderr, "%s(%02x)\n", __func__, prog_id);

  err = snd_seq_event_output (seq, &ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%02x): snd_seq_event_output failed %d\n", __func__, prog_id, err);
    return err;
  }

  err = snd_seq_drain_output(seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%02x): snd_seq_drain_output failed %d\n", __func__, prog_id, err);
    return err;
  }

  return 0;
}



enum ar_msg_type {
  AR_UNKNOWN,
  AR_DEVICE_INQUIRY,
  AR_CONTROL_WRITE,
  AR_STRING_WRITE,
  AR_ACK,
};

typedef struct {
  enum ar_msg_type type;
  union {
    struct {
      uint32_t id;
      uint8_t value;
    } control;
    struct {
      uint8_t device_id;
      uint8_t data[11];
    } inquiry;
    struct {
      uint8_t id;
      uint8_t data[16];
    } string;
  };
} ar_event_t;

int
sc_midi_arturia_dummy_read_control (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t read_ack, uint32_t control_id, uint8_t *val)
{
  fprintf(stderr, "%s(%08x)\n", __func__, control_id);
  *val = 0;
  return 0;
}

int
sc_midi_arturia_dummy_write_control (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, uint8_t val)
{
  fprintf(stderr, "%s(%08x, %d)\n", __func__, control_id, val);
  return 0;
}

int
sc_midi_arturia_dummy_read_string (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t read_ack, uint32_t control_id, char val[17])
{
  fprintf(stderr, "%s(%08x)\n", __func__, control_id);
  memset (val, 0, 16);
  return 0;
}

int
sc_midi_arturia_dummy_write_string (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, char val[17])
{
  fprintf(stderr, "%s(%08x, %s)\n", __func__, control_id, val);
  return 0;
}

int
sc_midi_arturia_dummy_recall_preset (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t preset_id)
{
  fprintf(stderr, "%s(%d)\n", __func__, preset_id);
  return 0;
}

int
sc_midi_arturia_dummy_store_preset (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t preset_id)
{
  fprintf(stderr, "%s(%d)\n", __func__, preset_id);
  return 0;
}

/*
 * device inquiry response:
 *        /--- Device ID
 *       vv
 * F0 7E 00 06 02 00 20 6B 02 00 04 02 43 07 00 01 F7
 *                ^^^^^^^^ ^^^^^ ^^^^^ ^^^^^^^^^^^
 *                       |   |     |
 *                       |   |     \------------------ Family ID
 *                       |   \------------------------ Family Member ID
 *                       \---------------------------- Arturia SysEx ID 3 bytes
 */

static void
process_arturia_message (snd_seq_event_t *ev, ar_event_t *ar_ev)
{
  static const uint8_t arturia_ack[] =          {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x1c, 0x00, 0xf7};
  static const uint8_t arturia_value[] =        {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x02};
  static const uint8_t arturia_value_p2[] =     {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x32};
  static const uint8_t arturia_value_p3[] =     {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x42};
  static const uint8_t arturia_v2_string[] =    {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x04};
  static const uint8_t arturia_v2_string_p2[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x34};
  static const uint8_t arturia_v2_string_p3[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x44};
  static const uint8_t arturia_v3_value[] =     {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x21};
  static const uint8_t device_inquiry[] =       {0xf0, 0x7e};

  unsigned int len = ev->data.ext.len;
  uint8_t* input = ev->data.ext.ptr;

  if (len == sizeof arturia_value + 5 &&
      memcmp (input, arturia_value, sizeof arturia_value) == 0)
  {
    ar_ev->control.id = (input[7] << 16) | (input[8] << 8) | input[9];
    ar_ev->control.value = input[10];
    ar_ev->type = AR_CONTROL_WRITE;
  }
  else if (len == sizeof arturia_value_p2 + 5 &&
      memcmp (input, arturia_value_p2, sizeof arturia_value_p2) == 0)
  {
    ar_ev->control.id = ((1 << 24) | (input[7] << 16) | (input[8] << 8) | input[9]);
    ar_ev->control.value = input[10];
    ar_ev->type = AR_CONTROL_WRITE;
  }
  else if (len == sizeof arturia_value_p3 + 5 &&
      memcmp (input, arturia_value_p3, sizeof arturia_value_p3) == 0)
  {
    ar_ev->control.id = ((2 << 24) | (input[7] << 16) | (input[8] << 8) | input[9]);
    ar_ev->control.value = input[10];
    ar_ev->type = AR_CONTROL_WRITE;
  }
  else if (len > sizeof arturia_v2_string + 5 &&
      memcmp (input, arturia_v2_string, sizeof arturia_v2_string) == 0)
  {
    ar_ev->string.id = (input[7] << 16) | (input[8] << 8) | input[9];
    memcpy (ar_ev->string.data, &input[10], min (len-10-1, 16));
    ar_ev->type = AR_STRING_WRITE;
  }
  else if (len > sizeof arturia_v2_string_p2 + 5 &&
      memcmp (input, arturia_v2_string_p2, sizeof arturia_v2_string_p2) == 0)
  {
    ar_ev->string.id = ((1 << 24) | input[7] << 16) | (input[8] << 8) | input[9];
    memcpy (ar_ev->string.data, &input[10], min (len-10-1, 16));
    ar_ev->type = AR_STRING_WRITE;
  }
  else if (len > sizeof arturia_v2_string_p3 + 5 &&
      memcmp (input, arturia_v2_string_p3, sizeof arturia_v2_string_p3) == 0)
  {
    ar_ev->string.id = ((2 << 24) | input[7] << 16) | (input[8] << 8) | input[9];
    memcpy (ar_ev->string.data, &input[10], min (len-10-1, 16));
    ar_ev->type = AR_STRING_WRITE;
  }
  else if (len == sizeof arturia_v3_value + 6 &&
      memcmp (input, arturia_v3_value, sizeof arturia_v3_value) == 0)
  {
    ar_ev->control.id = (input[7] << 24) | (input[8] << 16) | (input[9] << 8) | input[10];
    ar_ev->control.value = input[11];
    ar_ev->type = AR_CONTROL_WRITE;
  }
  else if (len == sizeof arturia_ack &&
           memcmp (input, arturia_ack, sizeof arturia_ack) == 0)
  {
    ar_ev->type = AR_ACK;
  }
  else if (len == sizeof device_inquiry + 15 &&
           memcmp (input, device_inquiry, sizeof device_inquiry) == 0 &&
           input[3] == 6 && input[4] == 2)
  {
    ar_ev->type = AR_DEVICE_INQUIRY;
    ar_ev->inquiry.device_id = input[2];
    memcpy (ar_ev->inquiry.data, &input[5], 11);
  }
  else
  {
    fprintf (stderr, "%s(%02d, %08x): unexpected message: len %d: ", __func__, ar_ev->type, ar_ev->control.id, len);
    for (int i=0; i < len; ++i)
      fprintf(stderr, "%02x ", (uint8_t)input[i]);
    fprintf(stderr, "\n");
    ar_ev->type = AR_UNKNOWN;
  }
}

static int
sc_midi_arturia_read_next (snd_seq_t *seq, ar_event_t *ar_ev)
{
  struct pollfd pfds[1] = {};
  ar_event_t ar_ev_in = {0};
  snd_seq_event_t *ev;
  int ret, pfds_n = 0;

  pfds_n = snd_seq_poll_descriptors(seq, pfds, 1, POLLIN);

  while (1)
  {
    if (snd_seq_event_input_pending (seq, 0) == 0)
    {
      ret = poll (pfds, pfds_n, READ_TIMEOUT_MS);
      if (ret < 0)
      {
        fprintf (stderr, "%s(%02d, %08x) poll failed %d\n", __func__, ar_ev->type, ar_ev->control.id, ret);
        return ret;
      }
      if (ret == 0)
      {
        fprintf (stderr, "%s(%02d, %08x) poll timeout %d\n", __func__, ar_ev->type, ar_ev->control.id, ret);
        return -ETIMEDOUT;
      }
    }

    while (1)
    {
      ret = snd_seq_event_input (seq, &ev);

      if (ret == -EAGAIN)
        break;

      if (ret < 0) {
        fprintf (stderr, "%s(%02d, %08x) snd_seq_event_input failed %d\n", __func__, ar_ev->type, ar_ev->control.id, ret);
        return ret;
      }

      process_arturia_message (ev, &ar_ev_in);

      if (ar_ev->type == ar_ev_in.type)
      {
        if (ar_ev->type == AR_CONTROL_WRITE && ar_ev->control.id && ar_ev->control.id != ar_ev_in.control.id)
        {
          fprintf (stderr, "%s(%02d, %08x): unexpected control %08x with value %02x\n", __func__, ar_ev->type, ar_ev->control.id, ar_ev_in.control.id, ar_ev_in.control.value);
          continue;
        }

        *ar_ev = ar_ev_in;
        return 0;
      }
      else
      {
        fprintf (stderr, "%s(%02d, %08x): unexpected message: type %02x\n", __func__, ar_ev->type, ar_ev->control.id, ar_ev_in.type);
      }

    }
  }
}

int
sc_midi_arturia_v3_write_control (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, uint8_t val)
{
  //                                                          prid  pid   cid   rid   val
  //                                                          ||||  ||||  ||||  ||||  ||||
  uint8_t data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7};
  snd_seq_event_t ev;
  int err;

  //printf ("write_control_value %08x value to %02x\n", control_id, val);

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, sizeof data, data);

  data[7] = (uint8_t)(control_id >> 24); // pr_id
  data[8] = (uint8_t)(control_id >> 16); // p_id
  data[9] = (uint8_t)(control_id >> 8); // c_id
  data[10] = (uint8_t)(control_id); // r_id
  data[11] = val;

  err = snd_seq_event_output (seq, &ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%08x): snd_seq_event_output failed %d\n", __func__, control_id, err);
    return err;
  }

  err = snd_seq_drain_output (seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%08x): snd_seq_drain_output failed %d\n", __func__, control_id, err);
    return err;
  }

  return 0;
}

int
sc_midi_arturia_v3_read_control (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t read_ack, uint32_t control_id, uint8_t *val)
{
  /**                                        
   *                                    prid pid cid rid
   * Out:   F0   00  20  6B  7F  42  20  08  40  00  00  F7  |  Sysex
   */
  uint8_t data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x20, 0x08, 0x00, 0x00, 0x00, 0xf7};
  ar_event_t ar_ev = {.type = AR_CONTROL_WRITE, .control.id = control_id};
  snd_seq_event_t ev;
  int err;

  //printf ("read_control_value 0x%08x\n", control_id);

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, sizeof data, data);

  data[7] = (uint8_t)(control_id >> 24); // pr_id
  data[8] = (uint8_t)(control_id >> 16); // p_id
  data[9] = (uint8_t)(control_id >> 8); // c_id
  data[10] = (uint8_t)(control_id); // r_id

  err = snd_seq_event_output (seq, &ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%08x): snd_seq_event_output failed %d\n", __func__, control_id, err);
    return err;
  }

  err = snd_seq_drain_output(seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%08x): snd_seq_drain_output failed %d\n", __func__, control_id, err);
    return err;
  }

  err = sc_midi_arturia_read_next (seq, &ar_ev);
  if (err < 0)
    return err;

  *val = ar_ev.control.value;

  return 0;
}

int
sc_midi_arturia_recall_preset (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t preset_id)
{
  //                                                          preset_id
  //                                                          ||||
  uint8_t data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x05, 0x00, 0xf7};
  snd_seq_event_t ev;
  int err;

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, sizeof data, data);

  data[7] = preset_id;

  //printf ("sc_midi_arturia_recall_preset %02x\n", preset_id);

  err = snd_seq_event_output (seq, &ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%02d): snd_seq_event_output failed %d\n", __func__, preset_id, err);
    return err;
  }

  err = snd_seq_drain_output (seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%02d): snd_seq_drain_output failed %d\n", __func__, preset_id, err);
    return err;
  }

  return 0;
}

int
sc_midi_arturia_store_preset (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t preset_id)
{
  //                                                          preset_id
  //                                                          ||||
  uint8_t data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x06, 0x00, 0xf7};
  snd_seq_event_t ev;
  int err;

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, sizeof data, data);

  data[7] = preset_id;

  //printf ("sc_midi_arturia_store_preset %02x\n", preset_id);

  err = snd_seq_event_output (seq, &ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%02d): snd_seq_event_output failed %d\n", __func__, preset_id, err);
    return err;
  }

  err = snd_seq_drain_output (seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%02d): snd_seq_drain_output failed %d\n", __func__, preset_id, err);
    return err;
  }

  return 0;
}

static void
set_control_id (uint8_t *data, uint32_t control_id)
{
  uint8_t r_id = (uint8_t)(control_id >> 24);
  data[7] = (uint8_t)(control_id >> 16); // pr_id
  data[8] = (uint8_t)(control_id >> 8); // p_id
  data[9] = (uint8_t)control_id; // c_id

  switch (r_id)
  {
    case 1: data[6] += 0x30; break;
    case 2: data[6] += 0x40; break;
    default: break;
  }
}

int
sc_midi_arturia_write_control (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, uint8_t val)
{
  //                                                         pr_id  p_id  c_id  value
  //                                                          ||||  ||||  ||||  ||||
  uint8_t data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x02, 0x00, 0x00, 0x00, 0x00, 0xf7};
  snd_seq_event_t ev;
  int err;

  //printf ("write_control_value %02x value to %02x\n", control_id, val);

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, sizeof data, data);

  set_control_id (data, control_id);
  data[10] = val;

  err = snd_seq_event_output (seq, &ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%08x): snd_seq_event_output failed %d\n", __func__, control_id, err);
    return err;
  }

  err = snd_seq_drain_output (seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%08x): snd_seq_drain_output failed %d\n", __func__, control_id, err);
    return err;
  }

  return 0;
}

int
sc_midi_arturia_read_control (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t read_ack, uint32_t control_id, uint8_t *val)
{
  //                                                         pr_id  p_id  c_id
  //                                                          ||||  ||||  ||||
  uint8_t data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x01, 0x00, 0x00, 0x00, 0xf7};
  ar_event_t ar_ev = {.type = AR_CONTROL_WRITE, .control.id = control_id};
  snd_seq_event_t ev;
  int err;

  //printf ("read_control_value %02x\n", control_id);

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, sizeof data, data);

  set_control_id (data, control_id);

  err = snd_seq_event_output (seq, &ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%04x) snd_seq_event_output failed %d\n", __func__, control_id, err);
    return err;
  }

  err = snd_seq_drain_output(seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%04x) snd_seq_drain_output failed %d\n", __func__, control_id, err);
    return err;
  }

  err = sc_midi_arturia_read_next (seq, &ar_ev);
  if (err < 0)
    return err;

  *val = ar_ev.control.value;

  if (read_ack)
    sc_midi_arturia_read_next (seq, &(ar_event_t){.type = AR_ACK, .control.id = control_id});
    // some controllers do not send ack, so not checking this is not an error
    // waiting for an ack makes the communication slow, so in this case we
    // can set read_ack to false

  return 0;
}

int
sc_midi_arturia_write_string (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, char val[17])
{
  //                                                           pr_id  p_id  c_id  value
  //                                                            ||||  ||||  ||||  ||||
  uint8_t data[28] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x04, 0x00, 0x00, 0x00};
  snd_seq_event_t ev;
  int err, len;

  memcpy (&data[10], val, 17);
  len = 10 + strlen (val);
  data[len++] = 0x00;
  data[len++] = 0xf7;

  //printf ("sc_midi_arturia_write_string %08x str ", control_id);
  //for (int i=10; i<len; ++i)
  //  printf ("%02x", data[i]);
  //printf ("\n");

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, len, data);

  set_control_id (data, control_id);

  err = snd_seq_event_output (seq, &ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%08x): snd_seq_event_output failed %d\n", __func__, control_id, err);
    return err;
  }

  err = snd_seq_drain_output (seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%08x): snd_seq_drain_output failed %d\n", __func__, control_id, err);
    return err;
  }

  return 0; 
}

int
sc_midi_arturia_read_string (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t read_ack, uint32_t control_id, char val[17])
{
  //                                                         pr_id  p_id  c_id
  //                                                          ||||  ||||  ||||
  uint8_t data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x03, 0x00, 0x00, 0x00, 0xf7};
  ar_event_t ar_ev = {.type = AR_STRING_WRITE, .control.id = control_id};
  snd_seq_event_t ev;
  int err;

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, sizeof data, data);

  set_control_id (data, control_id);

  err = snd_seq_event_output (seq, &ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%04x) snd_seq_event_output failed %d\n", __func__, control_id, err);
    return err;
  }

  err = snd_seq_drain_output(seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%04x) snd_seq_drain_output failed %d\n", __func__, control_id, err);
    return err;
  }

  err = sc_midi_arturia_read_next (seq, &ar_ev);
  if (err < 0)
    return err;

  memcpy (val, ar_ev.string.data, 16);
  val[16] = 0;

  if (read_ack)
    sc_midi_arturia_read_next (seq, &(ar_event_t){.type = AR_ACK, .control.id = control_id});
    // some controllers do not send ack, so not checking this is not an error
    // waiting for an ack makes the communication slow, so in this case we
    // can set read_ack to false

  return 0;
}

int
sc_midi_arturia_device_inquiry (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t data[11])
{
  uint8_t inq_data[] = {0xf0, 0x7e, 0x7f, 0x06, 0x01, 0xf7};
  ar_event_t ar_ev = {.type = AR_DEVICE_INQUIRY};
  snd_seq_event_t ev;
  int err;

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, sizeof inq_data, inq_data);

  err = snd_seq_event_output (seq, &ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(): snd_seq_event_output failed %d\n", __func__, err);
    return err;
  }

  err = snd_seq_drain_output (seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(): snd_seq_drain_output failed %d\n", __func__, err);
    return err;
  }

  err = sc_midi_arturia_read_next (seq, &ar_ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(): sc_midi_arturia_read_next failed %d\n", __func__, err);
    return err;
  }

  memcpy (data, ar_ev.inquiry.data, 11);

  return 0;
}

enum korg_msg_type {
  KORG_UNKNOWN,
  KORG_DEVICE_INQUIRY,
  KORG_SEARCH_REPLY,
  KORG_SCENE_DUMP,
  KORG_GLOBAL_DUMP,
  KORG_ACK,
  KORG_NAK,
  KORG_WRITE_COMPLETE,
  KORG_WRITE_ERROR,
  KORG_SCENE_CHANGE,
};

static const uint8_t KORG_GLOBAL_SCENE_ID = 0xff;

typedef struct {
  enum korg_msg_type type;
  union {
    struct {
      uint8_t device_id;
      uint8_t data[9];
    } inquiry;
    struct {
      uint8_t channel;
      uint8_t echo_id;
    } search_reply;
    struct {
      uint16_t size;
      uint8_t data[512];
    } dump;
    struct {
      uint8_t scene_id;
    } scene;
  };
} korg_event_t;

static void
process_korg_message (uint8_t *input, unsigned int len, korg_event_t *ev)
{
  const uint8_t device_inquiry[] = {0xf0, 0x7e};
  const uint8_t search_reply[] = {0xf0, 0x42, 0x50, 0x01};
  const uint8_t dump[] = {0xf0, 0x42};

  if (len == 15 &&
           memcmp (input, device_inquiry, sizeof device_inquiry) == 0 &&
           input[3] == 6 && input[4] == 2)
  {
    ev->type = KORG_DEVICE_INQUIRY;
    ev->inquiry.device_id = input[2];
    memcpy (ev->inquiry.data, &input[5], 9);
  }
  else if (len == 15 && memcmp (input, search_reply, sizeof search_reply) == 0)
  {
    ev->type = KORG_SEARCH_REPLY;
    ev->search_reply.channel = input[4];
    ev->search_reply.echo_id = input[5];
  }
  else if (len > 10 && len - 11 <= 512 && 
            memcmp (input, dump, sizeof dump) == 0 &&
            input[7] == 0x7F && (
              input[8] + 10 == len || (
              input[8] == 0x7f && input[9] == 0x02 && (input[10]<<7 | input[11]) + 13 == len))
        )
  {
    uint16_t idx = 0;
    uint16_t size = input[8] != 0x7f ? input[8] - 1 : (input[10]<<7 | input[11]) -1;
    uint8_t type = input[8] != 0x7f ? input[9] : input[12];
    uint8_t *data = input[8] != 0x7f ? &input[10] : &input[13];

    for (size_t i=0; i < size; i += 8)
      for (int j=0; j < 7; ++j)
        if (i+1+j < size)
          ev->dump.data[idx++] = data[i+1+j];

    if (type == 0x40) ev->type = KORG_SCENE_DUMP;
    else if (type == 0x51) ev->type = KORG_GLOBAL_DUMP;
    else ev->type = KORG_UNKNOWN;

    ev->dump.size = idx;
  }
  else if (len == 11 && memcmp (input, dump, sizeof dump) == 0 &&
            input[7] == 0x5F && input[8] == 0x23)
  {
    ev->type = KORG_ACK;
  }
  else if (len == 11 && memcmp (input, dump, sizeof dump) == 0 &&
            input[7] == 0x5F && input[8] == 0x24)
  {
    ev->type = KORG_NAK;
  }
  else if (len == 11 && memcmp (input, dump, sizeof dump) == 0 &&
            input[7] == 0x5F && input[8] == 0x21)
  {
    ev->type = KORG_WRITE_COMPLETE;
  }
  else if (len == 11 && memcmp (input, dump, sizeof dump) == 0 &&
            input[7] == 0x5F && input[8] == 0x22)
  {
    ev->type = KORG_WRITE_ERROR;
  }
  else if (len == 11 && memcmp (input, dump, sizeof dump) == 0 &&
            input[7] == 0x5F && input[8] == 0x4F)
  {
    ev->type = KORG_SCENE_CHANGE;
    ev->scene.scene_id = input[9];
  }
  else
  {
    fprintf (stderr, "%s(%02d): unexpected message: len %d: ", __func__, ev->type, len);
    for (int i=0; i < len; ++i)
      fprintf(stderr, "%02x ", (uint8_t)input[i]);
    fprintf(stderr, "\n");
    ev->type = KORG_UNKNOWN;
  }
}

static int
sc_midi_korg_read_next (snd_seq_t *seq, korg_event_t *ev)
{
  struct pollfd pfds[1] = {};
  korg_event_t tmp_ev = {0};
  int ret, pfds_n = 0;

  uint8_t sysex[SYSEX_BUFFER_SIZE];
  unsigned int sysex_len = 0;

  pfds_n = snd_seq_poll_descriptors(seq, pfds, 1, POLLIN);

  while (1)
  {
    if (snd_seq_event_input_pending (seq, 0) == 0)
    {
      ret = poll (pfds, pfds_n, READ_TIMEOUT_MS);
      if (ret < 0)
      {
        fprintf (stderr, "%s(%02d) poll failed %d\n", __func__, ev->type, ret);
        return ret;
      }
      if (ret == 0)
      {
        fprintf (stderr, "%s(%02d) poll timeout %d\n", __func__, ev->type, ret);
        return -ETIMEDOUT;
      }
    }

    while (1)
    {
      ret = sc_midi_read_sysex (seq, sysex, &sysex_len);

      if (ret == -EAGAIN)
        break;

      if (ret < 0) {
        fprintf (stderr, "%s(%02d) sc_midi_read_sysex failed %d\n", __func__, ev->type, ret);
        return ret;
      }

      process_korg_message (sysex, sysex_len, &tmp_ev);

      if (ev->type == tmp_ev.type)
      {
        *ev = tmp_ev;
        return 0;
      }
      else
      {
        fprintf (stderr, "%s(%02d): unexpected message: type %02x\n", __func__, ev->type, tmp_ev.type);
      }

    }
  }
}

int
sc_midi_korg_dummy_change_scene (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id)
{
  return 0;
}

int
sc_midi_korg_dummy_read_scene (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id, uint8_t data[512], uint16_t *size)
{
  return 0;
}

int
sc_midi_korg_dummy_write_scene (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id, uint8_t data[512], uint16_t size)
{
  return 0;
}

int
sc_midi_korg_dummy_save_scene (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id)
{
  return 0;
}

int
sc_midi_korg_device_inquiry (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t data[9])
{
  uint8_t inq_data[] = {0xf0, 0x7e, 0x7f, 0x06, 0x01, 0xf7};
  korg_event_t ev = {.type = KORG_DEVICE_INQUIRY};
  snd_seq_event_t seq_ev;
  int err;

  snd_seq_ev_clear (&seq_ev);
  snd_seq_ev_set_source (&seq_ev, 0);
  snd_seq_ev_set_dest (&seq_ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&seq_ev);
  snd_seq_ev_set_sysex (&seq_ev, sizeof inq_data, inq_data);

  err = snd_seq_event_output (seq, &seq_ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(): snd_seq_event_output failed %d\n", __func__, err);
    return err;
  }

  err = snd_seq_drain_output (seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(): snd_seq_drain_output failed %d\n", __func__, err);
    return err;
  }

  err = sc_midi_korg_read_next (seq, &ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(): sc_midi_korg_read_next failed %d\n", __func__, err);
    return err;
  }

  memcpy (data, ev.inquiry.data, 9);

  return 0;
}

static int
sc_midi_korg_read_channel (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t *channel)
{
  uint8_t query[] = {0xf0, 0x42, 0x50, 0x00, 0x00, 0xf7};
  korg_event_t ev = {.type = KORG_SEARCH_REPLY};
  snd_seq_event_t seq_ev;
  int err;

  snd_seq_ev_clear (&seq_ev);
  snd_seq_ev_set_source (&seq_ev, 0);
  snd_seq_ev_set_dest (&seq_ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&seq_ev);
  snd_seq_ev_set_sysex (&seq_ev, sizeof query, query);

  err = snd_seq_event_output (seq, &seq_ev);
  if (err < 0)
  {
    fprintf (stderr, "%s snd_seq_event_output failed %d\n", __func__, err);
    return err;
  }

  err = snd_seq_drain_output(seq);
  if (err < 0)
  {
    fprintf (stderr, "%s snd_seq_drain_output failed %d\n", __func__, err);
    return err;
  }

  err = sc_midi_korg_read_next (seq, &ev);
  if (err < 0)
    return err;

  *channel = ev.search_reply.channel;

  return 0;
}

int
sc_midi_korg_change_scene (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id)
{
  uint8_t query[] = {0xf0, 0x42, 0x40, dev_id[0], dev_id[1], dev_id[2], dev_id[3], 0x1f, 0x14, scene_id, 0xf7};
  korg_event_t ev1 = {.type = KORG_SCENE_CHANGE};
  korg_event_t ev2 = {.type = KORG_ACK};
  snd_seq_event_t seq_ev;
  int err;
  uint8_t channel;

  err = sc_midi_korg_read_channel(seq, addr, &channel);
  if (err < 0)
    return err;

  query[2] |= channel;

  snd_seq_ev_clear (&seq_ev);
  snd_seq_ev_set_source (&seq_ev, 0);
  snd_seq_ev_set_dest (&seq_ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&seq_ev);
  snd_seq_ev_set_sysex (&seq_ev, sizeof query, query);

  err = snd_seq_event_output (seq, &seq_ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%04x) snd_seq_event_output failed %d\n", __func__, scene_id, err);
    return err;
  }

  err = snd_seq_drain_output(seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%04x) snd_seq_drain_output failed %d\n", __func__, scene_id, err);
    return err;
  }

  err = sc_midi_korg_read_next (seq, &ev1);
  if (err < 0)
    return err;

  err = sc_midi_korg_read_next (seq, &ev2);
  if (err < 0)
    return err;

  return 0;
}

int
sc_midi_korg_read_scene (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id, uint8_t data[512], uint16_t *size)
{
  uint8_t typeid = scene_id == KORG_GLOBAL_SCENE_ID ? 0x0e : 0x10;
  uint8_t query[] = {0xf0, 0x42, 0x40, dev_id[0], dev_id[1], dev_id[2], dev_id[3], 0x1f, typeid, 0x00, 0xf7};
  korg_event_t ev = {.type = scene_id == KORG_GLOBAL_SCENE_ID ? KORG_GLOBAL_DUMP : KORG_SCENE_DUMP};
  snd_seq_event_t seq_ev;
  int err;
  uint8_t channel;

  err = sc_midi_korg_read_channel(seq, addr, &channel);
  if (err < 0)
    return err;

  query[2] |= channel;

  snd_seq_ev_clear (&seq_ev);
  snd_seq_ev_set_source (&seq_ev, 0);
  snd_seq_ev_set_dest (&seq_ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&seq_ev);
  snd_seq_ev_set_sysex (&seq_ev, sizeof query, query);

  err = snd_seq_event_output (seq, &seq_ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%04x) snd_seq_event_output failed %d\n", __func__, scene_id, err);
    return err;
  }

  err = snd_seq_drain_output(seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%04x) snd_seq_drain_output failed %d\n", __func__, scene_id, err);
    return err;
  }

  err = sc_midi_korg_read_next (seq, &ev);
  if (err < 0)
    return err;

  memcpy (data, ev.dump.data, ev.dump.size);
  *size = ev.dump.size;

  return 0;
}

int
sc_midi_korg_save_scene (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id)
{
  uint8_t query[] = {0xf0, 0x42, 0x40, dev_id[0], dev_id[1], dev_id[2], dev_id[3], 0x1f, 0x11, scene_id, 0xf7};
  snd_seq_event_t seq_ev;
  korg_event_t ack_ev = {.type=KORG_WRITE_COMPLETE};
  int err;
  uint8_t channel;

  if (scene_id == KORG_GLOBAL_SCENE_ID) return 0;

  err = sc_midi_korg_read_channel(seq, addr, &channel);
  if (err < 0)
    return err;

  query[2] |= channel;

  snd_seq_ev_clear (&seq_ev);
  snd_seq_ev_set_source (&seq_ev, 0);
  snd_seq_ev_set_dest (&seq_ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&seq_ev);
  snd_seq_ev_set_sysex (&seq_ev, sizeof query, query);

  err = snd_seq_event_output (seq, &seq_ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%04x): snd_seq_event_output failed %d\n", __func__, scene_id, err);
    return err;
  }

  err = snd_seq_drain_output (seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%04x): snd_seq_drain_output failed %d\n", __func__, scene_id, err);
    return err;
  }

  err = sc_midi_korg_read_next (seq, &ack_ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%04x): sc_midi_korg_read_next failed %d\n", __func__, scene_id, err);
    return err;
  }

  return 0;
}

int
sc_midi_korg_write_scene (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id, uint8_t data[512], uint16_t size)
{
  uint8_t query[1024] = {0xf0, 0x42, 0x40, dev_id[0], dev_id[1], dev_id[2], dev_id[3], 0x7f};
  snd_seq_event_t seq_ev;
  korg_event_t ack_ev = {.type=KORG_ACK};
  int err, cur = 8;
  uint16_t encoded_size = size / 7 * 8 + size % 7 + (size % 7 ? 1 : 0) + 1;
  uint8_t channel;

  err = sc_midi_korg_read_channel(seq, addr, &channel);
  if (err < 0)
    return err;

  query[2] |= channel;

  if (size > 512)
    return -EINVAL;

  if (encoded_size < 127) {
    query[cur++] = encoded_size;
  }
  else {
    query[cur++] = 0x7f;
    query[cur++] = 0x02;
    query[cur++] = encoded_size >> 7;
    query[cur++] = encoded_size & 0x7f;
  }
  query[cur++] = scene_id == KORG_GLOBAL_SCENE_ID ? 0x51 : 0x40;

  for (int i = 0; i * 7 < size; i++) {
    cur++; // skip first byte as we only have 7bit values yet
    for (int j = 0; j < 7; ++j)
      if (i * 7 + j < size)
        query[cur++] = data[i * 7 + j];
  }

  query[cur++] = 0xf7;

  /*fprintf (stderr, "%s(%04x)", __func__, scene_id);
  for (int i=0; i<len; ++i)
    fprintf (stderr, " %02x", query[i]);
  fprintf (stderr, "\n");*/

  snd_seq_ev_clear (&seq_ev);
  snd_seq_ev_set_source (&seq_ev, 0);
  snd_seq_ev_set_dest (&seq_ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&seq_ev);
  snd_seq_ev_set_sysex (&seq_ev, cur, query);

  err = snd_seq_event_output (seq, &seq_ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%04x): snd_seq_event_output failed %d\n", __func__, scene_id, err);
    return err;
  }

  err = snd_seq_drain_output (seq);
  if (err < 0)
  {
    fprintf (stderr, "%s(%04x): snd_seq_drain_output failed %d\n", __func__, scene_id, err);
    return err;
  }

  err = sc_midi_korg_read_next (seq, &ack_ev);
  if (err < 0)
  {
    fprintf (stderr, "%s(%04x): sc_midi_korg_read_next failed %d\n", __func__, scene_id, err);
    return err;
  }

  return 0; 
}

int
sc_midi_disconnect (snd_seq_t *seq, snd_seq_addr_t addr)
{
  int err;

  err = snd_seq_disconnect_from (seq, 0, addr.client, addr.port);
  if (err < 0) {
    fprintf (stderr, "snd_seq_disconnect_from(%d:%d) failed %d\n", addr.client, addr.port, err);
    return err;
  }

  err = snd_seq_disconnect_to (seq, 0, addr.client, addr.port);
  if (err < 0) {
    fprintf (stderr, "snd_seq_disconnect_to(%d:%d) failed %d\n", addr.client, addr.port, err);
    return err;
  }

  return err;
}

int
sc_midi_connect (snd_seq_t *seq, snd_seq_addr_t addr)
{
  int err;

  err = snd_seq_drop_input (seq);
  if (err < 0) {
    fprintf (stderr, "snd_seq_drop_input failed %d\n", err);
    return err;
  }

  err = snd_seq_drop_output (seq);
  if (err < 0) {
    fprintf (stderr, "snd_seq_drop_output failed %d\n", err);
    return err;
  }

  err = snd_seq_connect_from (seq, 0, addr.client, addr.port);
  if (err < 0) {
    fprintf (stderr, "snd_seq_connect_from(%d:%d) failed %d\n", addr.client, addr.port, err);
    return err;
  }

  err = snd_seq_connect_to (seq, 0, addr.client, addr.port);

  if (err < 0)
  {
    fprintf (stderr, "snd_seq_connect_to(%d:%d) failed %d\n", addr.client, addr.port, err);
    return err;
  }

  return err;
}

int
sc_midi_get_controllers (snd_seq_t *seq, sc_midi_info_t *controllers, int n, bool (filter)(sc_midi_info_t *))
{
  snd_seq_client_info_t *cinfo;
  snd_seq_port_info_t *pinfo;
  int i = 0;

  snd_seq_client_info_alloca (&cinfo);
  snd_seq_port_info_alloca (&pinfo);

  snd_seq_client_info_set_client (cinfo, -1);

  while (snd_seq_query_next_client (seq, cinfo) >= 0)
  {
    snd_seq_port_info_set_client (pinfo, snd_seq_client_info_get_client (cinfo));
    snd_seq_port_info_set_port (pinfo, -1);
    while (snd_seq_query_next_port (seq, pinfo) >= 0)
    {
      if ((snd_seq_port_info_get_capability (pinfo) & DESIRED_CAPS) != DESIRED_CAPS)
        continue;

      if (!(snd_seq_port_info_get_type (pinfo) & SND_SEQ_PORT_TYPE_HARDWARE))
        continue;

      if (i == n) {
        fprintf(stderr, "%s: truncated list at %d, some controllers may not appear\n", __func__, n);
        return i;
      }

      strncpy(controllers[i].client_name, snd_seq_client_info_get_name (cinfo), NAME_SIZE);
      strncpy(controllers[i].port_name, snd_seq_port_info_get_name (pinfo), NAME_SIZE);
      controllers[i].addr.client = snd_seq_client_info_get_client (cinfo);
      controllers[i].addr.port = snd_seq_port_info_get_port (pinfo);

      if (filter && !filter(&controllers[i]))
        continue;

      i++;
    }
  }
  return i;
}

int
sc_midi_open (snd_seq_t **seq)
{
  int err;

  err = snd_seq_open (seq, "default", SND_SEQ_OPEN_DUPLEX, SND_SEQ_NONBLOCK);
  if (err < 0)
  {
    fprintf (stderr, "snd_seq_open failed %d\n", err);
    return err;
  }

  snd_seq_set_client_name (*seq, "sysex-controls");

  err = snd_seq_create_simple_port (*seq, "listen:in", DESIRED_CAPS, SND_SEQ_PORT_TYPE_APPLICATION);
  if (err < 0)
  {
    fprintf(stderr, "snd_seq_create_simple_port failed %d\n", err);
    return err;
  }

  snd_seq_set_client_event_filter (*seq, SND_SEQ_EVENT_SYSEX);
  //snd_seq_set_client_event_filter (seq, SND_SEQ_EVENT_PORT_UNSUBSCRIBED);

  return err;
}

int
sc_midi_close (snd_seq_t **seq)
{
  int err = snd_seq_close (*seq);
  *seq = NULL;
  return err;
}
