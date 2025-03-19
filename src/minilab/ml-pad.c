#include "ml-pad.h"

struct _MlPad
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (MlPad, ml_pad, SC_TYPE_PREFERENCES_GROUP)

static void
ml_pad_class_init (MlPadClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab/ml-pad.ui");
}

static void
ml_pad_init (MlPad *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
