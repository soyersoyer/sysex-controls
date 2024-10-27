#include "ar3-active-ch-row.h"

struct _Ar3ActiveChRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (Ar3ActiveChRow, ar3_active_ch_row, SC_TYPE_COMBO_ROW)

static void
ar3_active_ch_row_class_init (Ar3ActiveChRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar3-active-ch-row.ui");
}

static void
ar3_active_ch_row_init (Ar3ActiveChRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
