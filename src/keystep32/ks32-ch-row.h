#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define KS32_TYPE_CH_ROW (ks32_ch_row_get_type ())

G_DECLARE_FINAL_TYPE (Ks32ChRow, ks32_ch_row, KS32, CH_ROW, ScComboRow)

G_END_DECLS
