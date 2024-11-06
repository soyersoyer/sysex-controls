#include "kles3-daw-control-row.h"

struct _Kles3DawControlRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3DawControlRow, kles3_daw_control_row, SC_TYPE_COMBO_ROW)

static void
kles3_daw_control_row_class_init (Kles3DawControlRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-daw-control-row.ui");
}

static void
kles3_daw_control_row_init (Kles3DawControlRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
