#include "amm2-knob.h"

struct _Amm2Knob
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm2Knob, amm2_knob, SC_TYPE_PREFERENCES_GROUP)

static void
amm2_knob_class_init (Amm2KnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini2/amm2-knob.ui");
}

static void
amm2_knob_init (Amm2Knob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
