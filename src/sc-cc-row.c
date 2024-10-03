#include "sc-cc-row.h"

#include "sc-control-value.h"

struct _ScCcRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (ScCcRow, sc_cc_row, SC_TYPE_COMBO_ROW)

static void
sc_cc_row_class_init (ScCcRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/sc-cc-row.ui");
}

static void
sc_cc_row_init (ScCcRow *self)
{
  g_type_ensure (SC_TYPE_CONTROL_VALUE_LIST);
  g_type_ensure (SC_TYPE_CONTROL_VALUE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
