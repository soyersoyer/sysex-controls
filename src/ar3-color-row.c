#include "ar3-color-row.h"

struct _Ar3ColorRow
{
  ScColorRow parent_instance;
};

G_DEFINE_FINAL_TYPE (Ar3ColorRow, ar3_color_row, SC_TYPE_COLOR_ROW)

static void
ar3_color_row_class_init (Ar3ColorRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar3-color-row.ui");
}

static void
ar3_color_row_init (Ar3ColorRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
