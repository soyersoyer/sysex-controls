#include "ml-knob.h"

struct _MlKnob
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (MlKnob, ml_knob, SC_TYPE_PREFERENCES_GROUP)

static void
ml_knob_class_init (MlKnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab/ml-knob.ui");
}

static void
ml_knob_init (MlKnob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
