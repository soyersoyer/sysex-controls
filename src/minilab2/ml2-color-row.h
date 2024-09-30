#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define ML2_TYPE_COLOR_ROW (ml2_color_row_get_type())

G_DECLARE_FINAL_TYPE (Ml2ColorRow, ml2_color_row, ML2, COLOR_ROW, ScComboRow)

G_END_DECLS

