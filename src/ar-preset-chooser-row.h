#pragma once

#include <adwaita.h>

#include "adw-action-row.h"

G_BEGIN_DECLS

#define AR_TYPE_PRESET_CHOOSER_ROW (ar_preset_chooser_row_get_type ())

G_DECLARE_FINAL_TYPE (ArPresetChooserRow, ar_preset_chooser_row, AR, PRESET_CHOOSER_ROW, AdwActionRow)

uint8_t ar_preset_chooser_row_get_preset_id (ArPresetChooserRow *self);
GtkWidget * ar_preset_chooser_row_new (uint8_t preset_id);

G_END_DECLS
