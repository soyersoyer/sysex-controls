#include "ksp-knob.h"

struct _KspKnob
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (KspKnob, ksp_knob, SC_TYPE_PREFERENCES_GROUP)

static void
ksp_knob_class_init (KspKnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keysteppro/ksp-knob.ui");
}

static void
ksp_knob_init (KspKnob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
