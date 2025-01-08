#include "ar2-user-all-ch-row.h"

struct _Ar2UserAllChRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (Ar2UserAllChRow, ar2_user_all_ch_row, SC_TYPE_COMBO_ROW)

static void
ar2_user_all_ch_row_class_init (Ar2UserAllChRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar2-user-all-ch-row.ui");
}

static void
ar2_user_all_ch_row_init (Ar2UserAllChRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
