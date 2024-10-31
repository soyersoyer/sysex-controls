#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define SC_TYPE_CH_ROW (sc_ch_row_get_type ())

G_DECLARE_FINAL_TYPE (ScChRow, sc_ch_row, SC, CH_ROW, ScComboRow)

G_END_DECLS
