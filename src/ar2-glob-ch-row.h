#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define AR2_TYPE_GLOB_CH_ROW (ar2_glob_ch_row_get_type ())

G_DECLARE_FINAL_TYPE (Ar2GlobChRow, ar2_glob_ch_row, AR2, GLOB_CH_ROW, ScComboRow)

G_END_DECLS
