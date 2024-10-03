#include "ml2-color-row.h"

#include "sc-control-value.h"

struct _Ml2ColorRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2ColorRow, ml2_color_row, SC_TYPE_COMBO_ROW)

static void
ml2_color_row_class_init (Ml2ColorRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-color-row.ui");
}

static void
ml2_color_row_init (Ml2ColorRow *self)
{
  g_type_ensure (SC_TYPE_CONTROL_VALUE_LIST);
  g_type_ensure (SC_TYPE_CONTROL_VALUE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
