#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define AR3_TYPE_CH_ROW (ar3_ch_row_get_type ())

G_DECLARE_FINAL_TYPE (Ar3ChRow, ar3_ch_row, AR3, CH_ROW, ScComboRow)

G_END_DECLS
