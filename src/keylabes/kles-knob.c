#include "kles-knob.h"

struct _KlesKnob
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesKnob, kles_knob, SC_TYPE_PREFERENCES_GROUP)

static void
kles_knob_class_init (KlesKnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-knob.ui");
}

static void
kles_knob_init (KlesKnob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
