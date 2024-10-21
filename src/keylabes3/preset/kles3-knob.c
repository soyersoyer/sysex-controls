#include "kles3-knob.h"

struct _Kles3Knob
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3Knob, kles3_knob, SC_TYPE_PREFERENCES_GROUP)

static void
kles3_knob_class_init (Kles3KnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/preset/kles3-knob.ui");
}

static void
kles3_knob_init (Kles3Knob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
