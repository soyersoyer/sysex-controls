#include "ar2-user-ch-row.h"

struct _Ar2UserChRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (Ar2UserChRow, ar2_user_ch_row, SC_TYPE_COMBO_ROW)

static void
ar2_user_ch_row_class_init (Ar2UserChRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar2-user-ch-row.ui");
}

static void
ar2_user_ch_row_init (Ar2UserChRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
