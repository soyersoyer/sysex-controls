#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define KS37_TYPE_MIDI_CONNECT (ks37_midi_connect_get_type())

G_DECLARE_FINAL_TYPE (Ks37MidiConnect, ks37_midi_connect, KS37, MIDI_CONNECT, AdwBin)

uint16_t ks37_midi_connect_get_control_id (Ks37MidiConnect *self);

G_END_DECLS

