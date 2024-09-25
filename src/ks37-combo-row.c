#include "ks37-combo-row.h"

#include "ks37-control-value.h"

struct _Ks37ComboRow
{
	AdwComboRow parent_instance;
};


G_DEFINE_FINAL_TYPE (Ks37ComboRow, ks37_combo_row, ADW_TYPE_COMBO_ROW)

static void
ks37_combo_row_class_init (Ks37ComboRowClass *klass)
{
}

static void
ks37_combo_row_init (Ks37ComboRow *self)
{
	GtkExpression *expression = gtk_property_expression_new (KS37_TYPE_CONTROL_VALUE, NULL, "name");
	adw_combo_row_set_expression (&self->parent_instance, expression);
}

