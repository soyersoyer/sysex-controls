#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define ML3_TYPE_CH_ROW (ml3_ch_row_get_type ())

G_DECLARE_FINAL_TYPE (Ml3ChRow, ml3_ch_row, ML3, CH_ROW, ScComboRow)

G_END_DECLS
