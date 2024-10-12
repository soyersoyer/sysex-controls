#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define BS_TYPE_CH_ROW (bs_ch_row_get_type ())

G_DECLARE_FINAL_TYPE (BsChRow, bs_ch_row, BS, CH_ROW, ScComboRow)

G_END_DECLS
