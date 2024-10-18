#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define KS37_TYPE_CH_ROW (ks37_ch_row_get_type ())

G_DECLARE_FINAL_TYPE (Ks37ChRow, ks37_ch_row, KS37, CH_ROW, ScComboRow)

G_END_DECLS
