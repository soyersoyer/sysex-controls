#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define SC_TYPE_COMBO_ROW (sc_combo_row_get_type ())

G_DECLARE_DERIVABLE_TYPE (ScComboRow, sc_combo_row, SC, COMBO_ROW, AdwComboRow)

struct _ScComboRowClass
{
  AdwComboRowClass parent_class;
};

G_END_DECLS
