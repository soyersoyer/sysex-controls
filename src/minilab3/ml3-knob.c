#include "ml3-knob.h"

struct _Ml3Knob
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3Knob, ml3_knob, SC_TYPE_PREFERENCES_GROUP)

static void
ml3_knob_class_init (Ml3KnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-knob.ui");
}

static void
ml3_knob_init (Ml3Knob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
