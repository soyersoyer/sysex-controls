#include "sc-ch-row-glob.h"

struct _ScChRowGlob
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (ScChRowGlob, sc_ch_row_glob, SC_TYPE_COMBO_ROW)

static void
sc_ch_row_glob_class_init (ScChRowGlobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/sc-ch-row-glob.ui");
}

static void
sc_ch_row_glob_init (ScChRowGlob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
