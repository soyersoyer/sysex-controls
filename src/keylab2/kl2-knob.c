#include "kl2-knob.h"

struct _Kl2Knob
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2Knob, kl2_knob, SC_TYPE_PREFERENCES_GROUP)

static void
kl2_knob_class_init (Kl2KnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-knob.ui");
}

static void
kl2_knob_init (Kl2Knob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
