#include <stdio.h>

#include "sc-midi.h"

#include "sc-util.h"

#define DESIRED_CAPS (SND_SEQ_PORT_CAP_READ | SND_SEQ_PORT_CAP_SUBS_READ | \
                      SND_SEQ_PORT_CAP_WRITE | SND_SEQ_PORT_CAP_SUBS_WRITE)


enum ar_msg_type {
  AR_UNKNOWN,
  AR_DEVICE_INQUIRY,
  AR_CONTROL_WRITE,
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
  };
} ar_event_t;

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
  static const char arturia_ack[] =      {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x1c, 0x00, 0xf7};
  static const char arturia_value[] =    {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x02, 0x00};
  static const char arturia_v3_value[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x21};
  static const char device_inquiry[] =   {0xf0, 0x7e};

  unsigned int len = ev->data.ext.len;
  char* input = ev->data.ext.ptr;

  if (len == ARRAY_SIZE (arturia_value) + 4 &&
      memcmp (input, arturia_value, ARRAY_SIZE (arturia_value)) == 0)
  {
    ar_ev->control.id = (input[8] << 8) | input[9];
    ar_ev->control.value = input[10];
    ar_ev->type = AR_CONTROL_WRITE;
  }
  else if (len == ARRAY_SIZE (arturia_v3_value) + 6 &&
      memcmp (input, arturia_v3_value, ARRAY_SIZE (arturia_v3_value)) == 0)
  {
    ar_ev->control.id = (input[7] << 24) | (input[8] << 16) | (input[9] << 8) | input[10];
    ar_ev->control.value = input[11];
    ar_ev->type = AR_CONTROL_WRITE;
  }
  else if (len == ARRAY_SIZE (arturia_ack) &&
           memcmp (input, arturia_ack, ARRAY_SIZE (arturia_ack)) == 0)
  {
    ar_ev->type = AR_ACK;
  }
  else if (len == ARRAY_SIZE (device_inquiry) + 15 &&
           memcmp (input, device_inquiry, ARRAY_SIZE (device_inquiry)) == 0 &&
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
    ret = poll (pfds, pfds_n, 20);
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

    }
  }
}

int
sc_midi_arturia_v3_write_control (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, uint8_t val)
{
  //                                                       prid  pid   cid   rid   val
  //                                                       ||||  ||||  ||||  ||||  ||||
  char data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7};
  snd_seq_event_t ev;
  int err;

  //printf ("write_control_value %08x value to %02x\n", control_id, val);

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, ARRAY_SIZE (data), data);

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
  char data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x20, 0x08, 0x00, 0x00, 0x00, 0xf7};
  ar_event_t ar_ev = {.type = AR_CONTROL_WRITE, .control.id = control_id};
  snd_seq_event_t ev;
  int err;

  //printf ("read_control_value 0x%08x\n", control_id);

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, ARRAY_SIZE (data), data);

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
  //                                                       preset_id
  //                                                       ||||
  char data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x05, 0x00, 0xf7};
  snd_seq_event_t ev;
  int err;

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, ARRAY_SIZE (data), data);

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
  //                                                       preset_id
  //                                                       ||||
  char data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x06, 0x00, 0xf7};
  snd_seq_event_t ev;
  int err;

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, ARRAY_SIZE (data), data);

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

int
sc_midi_arturia_write_control (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, uint8_t val)
{
  //                                                             p_id  c_id  value
  //                                                             ||||  ||||  ||||
  char data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x02, 0x00, 0x00, 0x00, 0x00, 0xf7};
  snd_seq_event_t ev;
  int err;

  //printf ("write_control_value %02x value to %02x\n", control_id, val);

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, ARRAY_SIZE (data), data);

  data[8] = (uint8_t)(control_id >> 8); // p_id
  data[9] = (uint8_t)control_id; // c_id
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
  //                                                             p_id  c_id
  //                                                             ||||  ||||
  char data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x01, 0x00, 0x00, 0x00, 0xf7};
  ar_event_t ar_ev = {.type = AR_CONTROL_WRITE, .control.id = control_id};
  snd_seq_event_t ev;
  int err;

  //printf ("read_control_value %02x\n", control_id);

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, ARRAY_SIZE (data), data);

  data[8] = (uint8_t)(control_id >> 8); // p_id
  data[9] = (uint8_t)control_id; // c_id

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
sc_midi_arturia_device_inquiry (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t data[11])
{
  char inq_data[] = {0xf0, 0x7e, 0x7f, 0x06, 0x01, 0xf7};
  ar_event_t ar_ev = {.type = AR_DEVICE_INQUIRY};
  snd_seq_event_t ev;
  int err;

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, ARRAY_SIZE (inq_data), inq_data);

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
sc_midi_get_controllers (snd_seq_t *seq, sc_midi_info_t *controllers, int n)
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

      if (i == n)
        return i;

      strncpy(controllers[i].client_name, snd_seq_client_info_get_name (cinfo), NAME_SIZE);
      strncpy(controllers[i].port_name, snd_seq_port_info_get_name (pinfo), NAME_SIZE);
      controllers[i].addr.client = snd_seq_client_info_get_client (cinfo);
      controllers[i].addr.port = snd_seq_port_info_get_port (pinfo);

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
