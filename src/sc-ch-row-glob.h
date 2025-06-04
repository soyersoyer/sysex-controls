#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define SC_TYPE_CH_ROW_GLOB (sc_ch_row_glob_get_type ())

G_DECLARE_FINAL_TYPE (ScChRowGlob, sc_ch_row_glob, SC, CH_ROW_GLOB, ScComboRow)

G_END_DECLS
