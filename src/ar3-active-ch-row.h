#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define AR3_TYPE_ACTIVE_CH_ROW (ar3_active_ch_row_get_type ())

G_DECLARE_FINAL_TYPE (Ar3ActiveChRow, ar3_active_ch_row, AR3, ACTIVE_CH_ROW, ScComboRow)

G_END_DECLS
