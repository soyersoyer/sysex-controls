#include "amm-knob.h"

struct _AmmKnob
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (AmmKnob, amm_knob, SC_TYPE_PREFERENCES_GROUP)

static void
amm_knob_class_init (AmmKnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini/amm-knob.ui");
}

static void
amm_knob_init (AmmKnob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
