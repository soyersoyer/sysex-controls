#pragma once

#include <adwaita.h>

#include "adw-action-row.h"

G_BEGIN_DECLS

#define BS_TYPE_PRESET_CHOOSER_ROW (bs_preset_chooser_row_get_type ())

G_DECLARE_FINAL_TYPE (BsPresetChooserRow, bs_preset_chooser_row, BS, PRESET_CHOOSER_ROW, AdwActionRow)

uint8_t bs_preset_chooser_row_get_preset_id (BsPresetChooserRow *self);
GtkWidget * bs_preset_chooser_row_new (uint8_t preset_id);

G_END_DECLS
