#include "ar2-glob2-ch-row.h"

struct _Ar2Glob2ChRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (Ar2Glob2ChRow, ar2_glob2_ch_row, SC_TYPE_COMBO_ROW)

static void
ar2_glob2_ch_row_class_init (Ar2Glob2ChRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar2-glob2-ch-row.ui");
}

static void
ar2_glob2_ch_row_init (Ar2Glob2ChRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
