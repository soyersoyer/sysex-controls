#include "sc-ch-row.h"

struct _ScChRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (ScChRow, sc_ch_row, SC_TYPE_COMBO_ROW)

static void
sc_ch_row_class_init (ScChRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/sc-ch-row.ui");
}

static void
sc_ch_row_init (ScChRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
