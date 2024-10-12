#include "bs-knob.h"

struct _BsKnob
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (BsKnob, bs_knob, SC_TYPE_PREFERENCES_GROUP)

static void
bs_knob_class_init (BsKnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-knob.ui");
}

static void
bs_knob_init (BsKnob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
