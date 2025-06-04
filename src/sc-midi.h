#pragma once

#include <stdint.h>

#include <alsa/asoundlib.h>

#define NAME_SIZE 128

typedef struct {
  char client_name[NAME_SIZE];
  char port_name[NAME_SIZE];
  snd_seq_addr_t addr;
} sc_midi_info_t;

int sc_midi_akai_dummy_read_program (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t query_cmd, uint8_t recv_cmd, uint8_t prog_id, uint8_t *data, uint16_t *size);
int sc_midi_akai_dummy_write_program (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t send_cmd, uint8_t prog_id, uint8_t *data, uint16_t size);
int sc_midi_akai_dummy_select_program (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t sel_cmd, uint8_t prog_id);

int sc_midi_akai_read_program (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t query_cmd, uint8_t recv_cmd, uint8_t prog_id, uint8_t *data, uint16_t *size);
int sc_midi_akai_write_program (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t send_cmd, uint8_t prog_id, uint8_t *data, uint16_t size);
int sc_midi_akai_select_program (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t sel_cmd, uint8_t prog_id);

int sc_midi_arturia_dummy_read_control (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t read_ack, uint32_t control_id, uint8_t *val);
int sc_midi_arturia_dummy_write_control (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, uint8_t val);
int sc_midi_arturia_dummy_read_string (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t read_ack, uint32_t control_id, char val[17]);
int sc_midi_arturia_dummy_write_string (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, char val[17]);

int sc_midi_arturia_dummy_recall_preset (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t preset_id);
int sc_midi_arturia_dummy_store_preset (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t preset_id);

int sc_midi_arturia_v3_read_control (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t read_ack, uint32_t control_id, uint8_t *val);
int sc_midi_arturia_v3_write_control (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, uint8_t val);
int sc_midi_arturia_recall_preset (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t preset_id);
int sc_midi_arturia_store_preset (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t preset_id);
int sc_midi_arturia_device_inquiry (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t data[11]);
int sc_midi_arturia_read_control (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t read_ack, uint32_t control_id, uint8_t *val);
int sc_midi_arturia_write_control (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, uint8_t val);
int sc_midi_arturia_read_string (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t read_ack, uint32_t control_id, char val[17]);
int sc_midi_arturia_write_string (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, char val[17]);

int sc_midi_korg_dummy_read_scene (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id, uint8_t data[512], uint16_t *size);
int sc_midi_korg_dummy_write_scene (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id, uint8_t data[512], uint16_t size);
int sc_midi_korg_dummy_save_scene (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id);

int sc_midi_korg_device_inquiry (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t data[9]);
int sc_midi_korg_read_scene (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id, uint8_t data[512], uint16_t *size);
int sc_midi_korg_write_scene (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id, uint8_t data[512], uint16_t size);
int sc_midi_korg_save_scene (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id);

int sc_midi_disconnect (snd_seq_t *seq, snd_seq_addr_t addr);
int sc_midi_connect (snd_seq_t *seq, snd_seq_addr_t addr);
int sc_midi_get_controllers (snd_seq_t *seq, sc_midi_info_t *controllers, int n);
int sc_midi_open (snd_seq_t **seq);
int sc_midi_close (snd_seq_t **seq);
