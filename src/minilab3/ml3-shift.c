#include "ml3-shift.h"

struct _Ml3Shift
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3Shift, ml3_shift, SC_TYPE_PREFERENCES_GROUP)

static void
ml3_shift_class_init (Ml3ShiftClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-shift.ui");
}

static void
ml3_shift_init (Ml3Shift *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
