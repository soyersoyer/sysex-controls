#include "kl3-pedal.h"

struct _Kl3Pedal
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3Pedal, kl3_pedal, SC_TYPE_PREFERENCES_GROUP)

static void
kl3_pedal_class_init (Kl3PedalClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/preset/kl3-pedal.ui");
}

static void
kl3_pedal_init (Kl3Pedal *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
