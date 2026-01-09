#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define KORG_TYPE_CC_NA_ROW (korg_cc_na_row_get_type ())

G_DECLARE_FINAL_TYPE (KorgCcNaRow, korg_cc_na_row, KORG, CC_NA_ROW, ScComboRow)

G_END_DECLS
