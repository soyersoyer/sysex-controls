#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define KLES3_TYPE_DAW_CONTROL_ROW (kles3_daw_control_row_get_type ())

G_DECLARE_FINAL_TYPE (Kles3DawControlRow, kles3_daw_control_row, KLES3, DAW_CONTROL_ROW, ScComboRow)

G_END_DECLS
