#include "bs-ch-row.h"

struct _BsChRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (BsChRow, bs_ch_row, SC_TYPE_COMBO_ROW)

static void
bs_ch_row_class_init (BsChRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-ch-row.ui");
}

static void
bs_ch_row_init (BsChRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
