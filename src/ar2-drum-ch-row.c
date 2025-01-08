#include "ar2-drum-ch-row.h"

struct _Ar2DrumChRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (Ar2DrumChRow, ar2_drum_ch_row, SC_TYPE_COMBO_ROW)

static void
ar2_drum_ch_row_class_init (Ar2DrumChRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar2-drum-ch-row.ui");
}

static void
ar2_drum_ch_row_init (Ar2DrumChRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
