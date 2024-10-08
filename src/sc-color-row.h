#pragma once

#include <adwaita.h>

#include "sc-control-value.h"

G_BEGIN_DECLS

#define SC_TYPE_COMBO_ROW (sc_color_row_get_type ())

G_DECLARE_DERIVABLE_TYPE (ScColorRow, sc_color_row, SC, COLOR_ROW, AdwComboRow)

struct _ScColorRowClass
{
  AdwComboRowClass parent_class;
};

gchararray cv_to_markup_color (GObject *object, ScControlValue* value);

G_END_DECLS
