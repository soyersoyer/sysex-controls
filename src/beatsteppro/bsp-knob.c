#include "bsp-knob.h"

struct _BspKnob
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (BspKnob, bsp_knob, SC_TYPE_PREFERENCES_GROUP)

static void
bsp_knob_class_init (BspKnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-knob.ui");
}

static void
bsp_knob_init (BspKnob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
