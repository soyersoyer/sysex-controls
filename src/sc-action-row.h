#pragma once

#include <adwaita.h>

#include "adw-action-row.h"
#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define SC_TYPE_ACTION_ROW (sc_action_row_get_type ())

G_DECLARE_FINAL_TYPE (ScActionRow, sc_action_row, SC, ACTION_ROW, AdwActionRow)

uint32_t sc_action_row_get_control_id_offset (ScActionRow *self);
uint32_t sc_action_row_get_control_cc_offset (ScActionRow *self);
GType sc_action_row_get_target_page (ScActionRow *self);

void sc_action_nav_push (ScActionRow *row, ScNavigationPage *page);

G_END_DECLS
