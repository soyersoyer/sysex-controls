#pragma once

#include <adwaita.h>

#include "sc-color-row.h"

G_BEGIN_DECLS

#define AR3_TYPE_COLOR_ROW (ar3_color_row_get_type ())

G_DECLARE_FINAL_TYPE (Ar3ColorRow, ar3_color_row, AR3, COLOR_ROW, ScColorRow)

G_END_DECLS
