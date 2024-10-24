#include "ar-ch-row.h"

struct _ArChRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (ArChRow, ar_ch_row, SC_TYPE_COMBO_ROW)

static void
ar_ch_row_class_init (ArChRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar-ch-row.ui");
}

static void
ar_ch_row_init (ArChRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
