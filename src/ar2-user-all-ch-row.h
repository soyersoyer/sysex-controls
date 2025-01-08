#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define AR2_TYPE_USER_ALL_CH_ROW (ar2_user_all_ch_row_get_type ())

G_DECLARE_FINAL_TYPE (Ar2UserAllChRow, ar2_user_all_ch_row, AR2, USER_ALL_CH_ROW, ScComboRow)

G_END_DECLS
