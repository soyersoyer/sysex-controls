#include "amm3-knob.h"

struct _Amm3Knob
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm3Knob, amm3_knob, SC_TYPE_PREFERENCES_GROUP)

static void
amm3_knob_class_init (Amm3KnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini3/amm3-knob.ui");
}

static void
amm3_knob_init (Amm3Knob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
