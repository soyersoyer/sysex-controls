#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define SC_TYPE_PC_ROW (sc_pc_row_get_type ())

G_DECLARE_FINAL_TYPE (ScPcRow, sc_pc_row, SC, PC_ROW, ScComboRow)

G_END_DECLS
