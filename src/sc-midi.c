#include <stdio.h>

#include "sc-midi.h"

#include "sc-util.h"

#define DESIRED_CAPS (SND_SEQ_PORT_CAP_READ | SND_SEQ_PORT_CAP_SUBS_READ | \
                      SND_SEQ_PORT_CAP_WRITE | SND_SEQ_PORT_CAP_SUBS_WRITE)


enum ar_msg_type {
  AR_WRITE_CONTROL,
  AR_ACK,
  AR_PAD_CHANGE,
  AR_PRESET_CHANGE,
  AR_UNEXPECTED,
};

int
sc_midi_arturia_v3_write_control (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, uint8_t val)
{
  //                                                             control_id        value
  //                                                       ||||||||||||||||||||||  ||||
  char data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7};
  //                                                       ||||  ||||  ||||  ||||
  //                                                     preset  pid   cid   rid
  //                                                    08:glob
  uint8_t pr_id = (uint8_t)(control_id >> 24);
  uint8_t p_id = (uint8_t)(control_id >> 16);
  uint8_t c_id = (uint8_t)(control_id >> 8);
  uint8_t r_id = (uint8_t)(control_id);
  snd_seq_event_t ev;
  int err;

  //printf ("write_control_value %08x value to %02x\n", control_id, val);

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, ARRAY_SIZE (data), data);

  data[7] = pr_id;
  data[8] = p_id;
  data[9] = c_id;
  data[10] = r_id;
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

static int
process_arturia_v3_message (snd_seq_event_t *ev, uint32_t control_id, uint8_t *val)
{
  /*                                 prid pid cid rid val
   * In:  F0  00  20  6B  7F  42  21  08  40  00  00  00  F7  |  Sysex
   *
   *
   * preset change from keyboard:            preset_number
   *                                         ||
   * F0  00  20  6B  7F  42  02  00  40  62  03  F7
   */

  static const char arturia_value[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x21};
  static const char pad_change[] =    {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x02, 0x00, 0x40, 0x63};
  static const char preset_change[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x02, 0x00, 0x40, 0x62};

  uint8_t pr_id = (uint8_t)(control_id >> 24);
  uint8_t p_id = (uint8_t)(control_id >> 16);
  uint8_t c_id = (uint8_t)(control_id >> 8);
  uint8_t r_id = (uint8_t)(control_id);

  unsigned int len = ev->data.ext.len;
  char* input = ev->data.ext.ptr;

  if (len == ARRAY_SIZE (arturia_value) + 6 &&
      memcmp (input, arturia_value, ARRAY_SIZE (arturia_value)) == 0)
  {
    if (input[7] == pr_id && input[8] == p_id && input[9] == c_id && input[10] == r_id)
    {
      *val = input[11];
      return AR_WRITE_CONTROL;
    }
    else
    {
      fprintf (stderr, "%s(%08x): unexpected control %02x%02x%02x%02x with value %02x\n", __func__, control_id, input[7], input[8], input[9], input[10], input[11]);
      return AR_UNEXPECTED;
    }
    //printf ("MIDI VALUE %02x%02x -> %02x\n", input[8], input[9], input[10]);
  }
  else if (len == ARRAY_SIZE (pad_change) + 2 &&
           memcmp (input, pad_change, ARRAY_SIZE (pad_change)) == 0)
  {
    fprintf (stderr, "%s(%08x): pad_change\n", __func__, control_id);
    return AR_PAD_CHANGE;
  }
  else if (len == ARRAY_SIZE (preset_change) + 2 &&
           memcmp (input, preset_change, ARRAY_SIZE (preset_change)) == 0)
  {
    fprintf (stderr, "%s(%08x): preset_change\n", __func__, control_id);
    return AR_PRESET_CHANGE;
  }
  else
  {
    fprintf (stderr, "%s(%08x): unexpected message: len %d: ", __func__, control_id, len);
    for (int i=0; i < len; ++i)
      fprintf(stderr, "%02x ", (uint8_t)input[i]);
    fprintf(stderr, "\n");
    return AR_UNEXPECTED;
  }
}

int
sc_midi_arturia_v3_read_control (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t read_ack, uint32_t control_id, uint8_t *val)
{
  /**                                        
   *                                        pid cid
   * Out:   F0   00  20  6B  7F  42  20  08  40  00  00  F7  |  Sysex
   */
  char data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x20, 0x08, 0x00, 0x00, 0x00, 0xf7};
  uint8_t pr_id = (uint8_t)(control_id >> 24);
  uint8_t p_id = (uint8_t)(control_id >> 16);
  uint8_t c_id = (uint8_t)(control_id >> 8);
  uint8_t r_id = (uint8_t)(control_id);
  snd_seq_event_t ev, *ev_input;
  struct pollfd pfds[1] = {};
  int err, pfds_n = 0;

  //printf ("read_control_value 0x%08x\n", control_id);

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, ARRAY_SIZE (data), data);

  data[7] = pr_id;
  data[8] = p_id;
  data[9] = c_id;
  data[10] = r_id;

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

  pfds_n = snd_seq_poll_descriptors(seq, pfds, 1, POLLIN);

  while (1)
  {
    err = poll (pfds, pfds_n, 20);
    if (err < 0)
    {
      fprintf (stderr, "%s(%08x): poll failed %d\n", __func__, control_id, err);
      return err;
    }
    if (err == 0)
    {
      fprintf (stderr, "%s(%08x): poll timeout %d\n", __func__, control_id, err);
      return -ETIMEDOUT;
    }

    while (1)
    {
      err = snd_seq_event_input (seq, &ev_input);

      if (err == -EAGAIN)
        break;

      if (err < 0)
      {
        fprintf (stderr, "%s(%08x) snd_seq_event_input failed %d\n", __func__, control_id, err);
        return err;
      }

      err = process_arturia_v3_message (ev_input, control_id, val);

      if (err == AR_WRITE_CONTROL)
        return 0;
    }
  }
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
  //                                                             control_id  value
  //                                                             ||||||||||  ||||
  char data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x02, 0x00, 0x00, 0x00, 0x00, 0xf7};
  uint8_t p_id = (uint8_t)(control_id >> 8);
  uint8_t c_id = (uint8_t)control_id;
  snd_seq_event_t ev;
  int err;

  //printf ("write_control_value %02x value to %02x\n", control_id, val);

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, ARRAY_SIZE (data), data);

  data[8] = p_id;
  data[9] = c_id;
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

static int
process_arturia_message (snd_seq_event_t *ev, uint32_t control_id, uint8_t *val)
{
  static const char arturia_ack[] =   {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x1c, 0x00, 0xf7};
  static const char arturia_value[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x02, 0x00};

  uint8_t p_id = (uint8_t)(control_id >> 8);
  uint8_t c_id = (uint8_t)control_id;

  unsigned int len = ev->data.ext.len;
  char* input = ev->data.ext.ptr;

  if (len == ARRAY_SIZE (arturia_value) + 4 &&
      memcmp (input, arturia_value, ARRAY_SIZE (arturia_value)) == 0)
  {
    if (input[8] == p_id && input[9] == c_id)
    {
      *val = input[10];
      return AR_WRITE_CONTROL;
    }
    else
    {
      fprintf (stderr, "%s(%04x): unexpected control %02x%02x with value %02x\n", __func__, control_id, input[8], input[9], input[10]);
      return AR_UNEXPECTED;
    }
    //printf ("MIDI VALUE %02x%02x -> %02x\n", input[8], input[9], input[10]);
  }
  else if (len == ARRAY_SIZE (arturia_ack) &&
           memcmp (input, arturia_ack, ARRAY_SIZE (arturia_ack)) == 0)
  {
    return AR_ACK;
  }
  else
  {
    fprintf (stderr, "%s(%04x): unexpected message: len %d: ", __func__, control_id, len);
    for (int i=0; i < len; ++i)
      fprintf(stderr, "%02x ", (uint8_t)input[i]);
    fprintf(stderr, "\n");
    return AR_UNEXPECTED;
  }
}

static int
sc_midi_arturia_read_next (snd_seq_t *seq, enum ar_msg_type type, uint32_t control_id, uint8_t *val)
{
  struct pollfd pfds[1] = {};
  snd_seq_event_t *ev;
  int ret, pfds_n = 0;

  pfds_n = snd_seq_poll_descriptors(seq, pfds, 1, POLLIN);

  while (1)
  {
    ret = poll (pfds, pfds_n, 20);
    if (ret < 0)
    {
      fprintf (stderr, "%s(%02d, %04x) poll failed %d\n", __func__, type, control_id, ret);
      return ret;
    }
    if (ret == 0)
    {
      fprintf (stderr, "%s(%02d, %04x) poll timeout %d\n", __func__, type, control_id, ret);
      return -ETIMEDOUT;
    }

    while (1)
    {
      ret = snd_seq_event_input (seq, &ev);

      if (ret == -EAGAIN)
        break;

      if (ret < 0) {
        fprintf (stderr, "%s(%02d, %04x) snd_seq_event_input failed %d\n", __func__, type, control_id, ret);
        return ret;
      }

      ret = process_arturia_message (ev, control_id, val);

      if (ret == type)
        return 0;
    }
  }
}

int
sc_midi_arturia_read_control (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t read_ack, uint32_t control_id, uint8_t *val)
{
  //                                                             control_id
  //                                                             ||||||||||
  char data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x01, 0x00, 0x00, 0x00, 0xf7};
  uint8_t p_id = (uint8_t)(control_id >> 8);
  uint8_t c_id = (uint8_t)control_id;
  int ret;
  snd_seq_event_t ev;

  //printf ("read_control_value %02x\n", control_id);

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, ARRAY_SIZE (data), data);

  data[8] = p_id;
  data[9] = c_id;

  ret = snd_seq_event_output (seq, &ev);
  if (ret < 0)
  {
    fprintf (stderr, "%s(%04x) snd_seq_event_output failed %d\n", __func__, control_id, ret);
    return ret;
  }

  ret = snd_seq_drain_output(seq);

  if (ret < 0)
  {
    fprintf (stderr, "%s(%04x) snd_seq_drain_output failed %d\n", __func__, control_id, ret);
    return ret;
  }

  ret = sc_midi_arturia_read_next (seq, AR_WRITE_CONTROL, control_id, val);
  if (ret < 0)
    return ret;

  if (read_ack)
    sc_midi_arturia_read_next (seq, AR_ACK, control_id, val);
    // some controllers do not send ack, so not checking this is not an error
    // waiting for an ack makes the communication slow, so in this case we
    // can set read_ack to false

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
