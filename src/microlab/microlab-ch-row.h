#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define MICROLAB_TYPE_CH_ROW (microlab_ch_row_get_type ())

G_DECLARE_FINAL_TYPE (MicrolabChRow, microlab_ch_row, MICROLAB, CH_ROW, ScComboRow)

G_END_DECLS
