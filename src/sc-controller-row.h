#pragma once

#include <adwaita.h>

#include "sc-midi.h"

G_BEGIN_DECLS

#define SC_TYPE_CONTROLLER_ROW (sc_controller_row_get_type ())

G_DECLARE_FINAL_TYPE (ScControllerRow, sc_controller_row, SC, CONTROLLER_ROW, AdwActionRow)

G_END_DECLS

GtkWidget * sc_controller_row_new (sc_midi_info_t *info);
sc_midi_info_t * sc_controller_row_get_info (ScControllerRow *self);
