#include "ml2-ch-row.h"

struct _Ml2ChRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2ChRow, ml2_ch_row, SC_TYPE_COMBO_ROW)

static void
ml2_ch_row_class_init (Ml2ChRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-ch-row.ui");
}

static void
ml2_ch_row_init (Ml2ChRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
