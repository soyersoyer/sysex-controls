#pragma once

#include <adwaita.h>

#include "adw-action-row.h"

G_BEGIN_DECLS

#define SC_TYPE_ACTION_ROW (sc_action_row_get_type ())

G_DECLARE_FINAL_TYPE (ScActionRow, sc_action_row, SC, ACTION_ROW, AdwActionRow)

uint32_t sc_action_row_get_control_id_offset (ScActionRow *self);
uint32_t sc_action_row_get_control_cc_offset (ScActionRow *self);

G_END_DECLS
