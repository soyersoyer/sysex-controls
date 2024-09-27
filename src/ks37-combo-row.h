#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define KS37_TYPE_COMBO_ROW (ks37_combo_row_get_type())

G_DECLARE_DERIVABLE_TYPE (Ks37ComboRow, ks37_combo_row, KS37, COMBO_ROW, AdwComboRow)

struct _Ks37ComboRowClass
{
	AdwComboRowClass parent_class;
};

G_END_DECLS


