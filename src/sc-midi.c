#include <stdio.h>

#include "sc-midi.h"

#define DESIRED_CAPS (SND_SEQ_PORT_CAP_READ | SND_SEQ_PORT_CAP_SUBS_READ | \
                      SND_SEQ_PORT_CAP_WRITE | SND_SEQ_PORT_CAP_SUBS_WRITE)

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

int
sc_midi_arturia_write_control (snd_seq_t *seq, snd_seq_addr_t addr, uint16_t control_id, uint8_t val)
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
    fprintf (stderr, "write_control_value snd_seq_event_output failed %d\n", err);
    return err;
  }

  err = snd_seq_drain_output (seq);
  if (err < 0)
  {
    fprintf (stderr, "write_control_value snd_seq_drain_output failed %d\n", err);
    return err;
  }

  return 0;
}

static int
process_sysex_message (snd_seq_t *seq, struct pollfd *pfds, uint8_t pfds_n, uint8_t p_id, uint8_t c_id, int *set, uint8_t *val)
{
  //static const char arturia_ack[] =   {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x1c, 0x00, 0xf7};
  static const char arturia_value[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x02, 0x00};

  snd_seq_event_t *ev_input;
  int ret;

  unsigned int len;
  char* input;

  ret = poll (pfds, pfds_n, 20);
  if (ret < 0)
  {
    fprintf (stderr, "poll failed %d\n", ret);
    return ret;
  }
  if (ret == 0)
  {
    fprintf (stderr, "poll timeout %d\n", ret);
    return -ETIMEDOUT;
  }

  ret = snd_seq_event_input (seq, &ev_input);
  if (ret < 0)
  {
    fprintf (stderr, "snd_seq_event_input failed %d\n", ret);
    return ret;
  }

  len = ev_input->data.ext.len;
  input = ev_input->data.ext.ptr;

  if (memcmp (input, arturia_value, MIN (len, ARRAY_SIZE (arturia_value))) == 0 &&
      len == ARRAY_SIZE (arturia_value) + 4)
  {
    if (input[8] == p_id && input[9] == c_id)
    {
      *val = input[10];
      *set = 1;
    }
    else
    {
      fprintf (stderr, "process_sysex_message: unexpected control %02x%02x with value %02x\n", input[8], input[9], input[10]);
    }
    //printf ("MIDI VALUE %02x%02x -> %02x\n", input[8], input[9], input[10]);
  }
  return 0;
}

static int
process_control_event (snd_seq_t *seq, uint8_t p_id, uint8_t c_id, uint8_t *val)
{
  int ret, set = 0, pfds_n = 0;

  struct pollfd pfds[1] = {};
  pfds_n = snd_seq_poll_descriptors(seq, pfds, 1, POLLIN);

  // read value
  ret = process_sysex_message (seq, pfds, pfds_n, p_id, c_id, &set, val);
  if (ret < 0)
    return ret;

  // read ack
  ret = process_sysex_message (seq, pfds, pfds_n, p_id, c_id, &set, val);
  if (ret < 0)
    return ret;

  return set ? 0 : -EIO;
}

int
sc_midi_arturia_read_control (snd_seq_t *seq, snd_seq_addr_t addr, uint16_t control_id, uint8_t *val)
{
  //                                                             control_id
  //                                                             ||||||||||
  char data[] = {0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x01, 0x00, 0x00, 0x00, 0xf7};
  uint8_t p_id = (uint8_t)(control_id >> 8);
  uint8_t c_id = (uint8_t)control_id;
  snd_seq_event_t ev;
  int err;

  //printf ("read_control_value %02x\n", control_id);

  snd_seq_ev_clear (&ev);
  snd_seq_ev_set_source (&ev, 0);
  snd_seq_ev_set_dest (&ev, addr.client, addr.port);
  snd_seq_ev_set_direct (&ev);
  snd_seq_ev_set_sysex (&ev, ARRAY_SIZE (data), data);

  data[8] = p_id;
  data[9] = c_id;

  err = snd_seq_event_output (seq, &ev);
  if (err < 0)
  {
    fprintf (stderr, "read_control_value(%02x) snd_seq_event_output failed %d\n", control_id, err);
    return err;
  }

  err = snd_seq_drain_output(seq);

  if (err < 0)
  {
    fprintf (stderr, "read_control_value(%02x) snd_seq_drain_output failed %d\n", control_id, err);
    return err;
}

  return process_control_event (seq, p_id, c_id, val);
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
