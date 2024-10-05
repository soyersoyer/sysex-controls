#include "sc-pc-row.h"

struct _ScPcRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (ScPcRow, sc_pc_row, SC_TYPE_COMBO_ROW)

static void
sc_pc_row_class_init (ScPcRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/sc-pc-row.ui");
}

static void
sc_pc_row_init (ScPcRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
