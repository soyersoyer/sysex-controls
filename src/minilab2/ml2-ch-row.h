#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define ML2_TYPE_CH_ROW (ml2_ch_row_get_type ())

G_DECLARE_FINAL_TYPE (Ml2ChRow, ml2_ch_row, ML2, CH_ROW, ScComboRow)

G_END_DECLS
