#include "sc-combo-row.h"

#include "sc-control-value.h"

G_DEFINE_TYPE (ScComboRow, sc_combo_row, ADW_TYPE_COMBO_ROW)

static void
sc_combo_row_class_init (ScComboRowClass *klass)
{
}

static void
sc_combo_row_init (ScComboRow *self)
{
  GtkExpression *expression = gtk_property_expression_new (SC_TYPE_CONTROL_VALUE, NULL, "name");
  adw_combo_row_set_expression (&self->parent_instance, expression);
}
