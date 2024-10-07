#include "ml3-main-knob.h"

struct _Ml3MainKnob
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3MainKnob, ml3_main_knob, SC_TYPE_PREFERENCES_GROUP)

static void
ml3_main_knob_class_init (Ml3MainKnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-main-knob.ui");
}

static void
ml3_main_knob_init (Ml3MainKnob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
