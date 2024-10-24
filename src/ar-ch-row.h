#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define AR_TYPE_CH_ROW (ar_ch_row_get_type ())

G_DECLARE_FINAL_TYPE (ArChRow, ar_ch_row, AR, CH_ROW, ScComboRow)

G_END_DECLS
