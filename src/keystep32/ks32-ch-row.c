#include "ks32-ch-row.h"

struct _Ks32ChRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks32ChRow, ks32_ch_row, SC_TYPE_COMBO_ROW)

static void
ks32_ch_row_class_init (Ks32ChRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep32/ks32-ch-row.ui");
}

static void
ks32_ch_row_init (Ks32ChRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
