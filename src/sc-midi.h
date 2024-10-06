#pragma once

#include <stdint.h>

#include <alsa/asoundlib.h>

/* KeyStep 37 SysEx
 *
 * send control read request:
 * -> 0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x01, 0x00, 0x41, id, 0xf7
 * receive response:
 * <- 0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x02, 0x00, 0x41, id, value, 0xf7
 * receive ack
 * <- 0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x1c, 0x00, 0xf7
 *
 * send control write request:
 * -> 0xf0, 0x00, 0x20, 0x6b, 0x7f, 0x42, 0x02, 0x00, 0x41, id, value, 0xf7
 */

#define P_USER_CHANNEL			0x03  // 0-15
#define P_INPUT_CHANNEL			0x01  // 0-15, userchannel=0x41
#define P_MIDI_THRU			0x02  // off=0,on=1
#define P_VELOCITY_CURVE		0x06  // lin=0,log=1,antilog=2
#define P_AFTERTOUCH_CURVE		0x07  // lin=0,log=1,antilog=2,soft=3
#define P_KNOB_CATCHUP			0x2E  // 0=jump,1=hook,2=scale
#define P_HOLD_SWITCH_FUNCTION		0x6F  // 1=hold, 2=sustain, 3=both
#define P_SUSTAIN_PEDAL_FUNCTION	0x70  // 1=hold, 2=sustain, 3=both

#define P_SYNC_CLOCK_IO			0x08  // 0=gate,clock=1,korg=2,24=3,48=4
#define P_MIDI_CLOCK_START		0x0B  // clk=0, gate=1
#define P_NEXT_SEQ			0x0C  // end=0, reset=1, continue=2
#define P_TRANSPOSITION_INPUT_PORT	0x0F  // usb=1, midi=2, both=3
#define P_TRANSPOSE_INPUT_CHANNEL	0x09  // 0-15, none=0x10
#define P_TRANSPOSITION_LATCH		0x0E  // off=0, on=1
#define P_TRANSPOSE_CENTER_PITCH	0x13  // C-2=0 ... G8=7F
#define P_VELOCITY			0x11  // as recorded=0, fixed=1
#define P_FIXED_VELOCITY_VALUE		0x12  // 1-127
#define P_TAP_TEMPO_AVERAGE		0x0A  // 3-6
#define P_ARM_TO_START			0x15  // off=0, on=1
#define P_TIE_MODE			0x16  // to previous=0, to next=1
#define P_SEQUENCE_LENGTH_UPDATE	0x17  // keep=0, clear=1

#define P_PITCH_CV_OUTPUT		0x18  // volt=0, hertz=1
#define P_0V_MIDI_NOTE			0x1A  // C-2=0 ... G8=7F
#define P_1V_MIDI_NOTE			0x1B  // C-2=0 ... G8=7F
#define P_NOTE_PRIORITY			0x1C  // low=0, high=1, last=2
#define P_MOD_CV_SOURCE			0x1D  // modwheel=0, velocity=1, aftertouch=2
#define P_MOD_CV_MAX_VOLTAGE		0x1E  // 5V=5, 12v=0x0C
#define P_PITCH_BEND_RANGE		0x1F  // 1-24
#define P_GATE_CV_OUTPUT		0x19  // s-trig=0, 5V=1, 12V=2

#define P_PLAY_PAUSE			0x27  // pause=0, reset=1
#define P_TRANSPORT_MODE		0x20  // off=0, midi=1, mmc=2, both=3

#define P_BANK1_KNOB1_CC		0x2f  // 0-127
#define P_BANK1_KNOB1_MIN		0x30  // 0-127
#define P_BANK1_KNOB1_MAX		0x31  // 0-127
#define P_BANK1_KNOB1_CHAN		0x32  // 0-15, user=0x41

#define P_BANK1_KNOB2_CC		0x33  // 0-127
#define P_BANK1_KNOB2_MIN		0x34  // 0-127
#define P_BANK1_KNOB2_MAX		0x35  // 0-127
#define P_BANK1_KNOB2_CHAN		0x36  // 0-15, user=0x41

// ...

#define P_BANK4_KNOB4_CC		0x6B  // 0-127
#define P_BANK4_KNOB4_MIN		0x6C  // 0-127
#define P_BANK4_KNOB4_MAX		0x6D  // 0-127
#define P_BANK4_KNOB4_CHAN		0x6E  // 0-15, user=0x41

#define NAME_SIZE 128

typedef struct {
  char client_name[NAME_SIZE];
  char port_name[NAME_SIZE];
  snd_seq_addr_t addr;
} sc_midi_info_t;

int sc_midi_arturia_v3_read_control (snd_seq_t *seq, snd_seq_addr_t addr, uint16_t control_id, uint8_t *val);
int sc_midi_arturia_v3_write_control (snd_seq_t *seq, snd_seq_addr_t addr, uint16_t control_id, uint8_t val);
int sc_midi_arturia_read_control (snd_seq_t *seq, snd_seq_addr_t addr, uint16_t control_id, uint8_t *val);
int sc_midi_arturia_write_control (snd_seq_t *seq, snd_seq_addr_t addr, uint16_t control_id, uint8_t val);
int sc_midi_disconnect (snd_seq_t *seq, snd_seq_addr_t addr);
int sc_midi_connect (snd_seq_t *seq, snd_seq_addr_t addr);
int sc_midi_get_controllers (snd_seq_t *seq, sc_midi_info_t *controllers, int n);
int sc_midi_open (snd_seq_t **seq);
int sc_midi_close (snd_seq_t **seq);
