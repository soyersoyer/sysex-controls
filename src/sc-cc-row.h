#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define SC_TYPE_CC_ROW (sc_cc_row_get_type ())

G_DECLARE_FINAL_TYPE (ScCcRow, sc_cc_row, SC, CC_ROW, ScComboRow)

G_END_DECLS

