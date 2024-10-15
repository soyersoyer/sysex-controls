#include "ml2-knob.h"

struct _Ml2Knob
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2Knob, ml2_knob, SC_TYPE_PREFERENCES_GROUP)

static void
ml2_knob_class_init (Ml2KnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-knob.ui");
}

static void
ml2_knob_init (Ml2Knob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
