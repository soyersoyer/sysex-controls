#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define SC_TYPE_MIDI_CONNECT (sc_midi_connect_get_type ())

G_DECLARE_FINAL_TYPE (ScMidiConnect, sc_midi_connect, SC, MIDI_CONNECT, AdwBin)

uint16_t sc_midi_connect_get_control_id (ScMidiConnect *self);

G_END_DECLS

