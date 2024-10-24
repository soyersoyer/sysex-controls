#pragma once

#include <adwaita.h>

#include "adw-action-row.h"

G_BEGIN_DECLS

#define AR2_TYPE_RGB_COLOR_ROW (ar2_rgb_color_row_get_type ())

G_DECLARE_FINAL_TYPE (Ar2RgbColorRow, ar2_rgb_color_row, AR2, RGB_COLOR_ROW, AdwActionRow)

G_END_DECLS
