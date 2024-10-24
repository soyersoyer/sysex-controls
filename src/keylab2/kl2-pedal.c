#include "kl2-pedal.h"

struct _Kl2Pedal
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2Pedal, kl2_pedal, SC_TYPE_PREFERENCES_GROUP)

static void
kl2_pedal_class_init (Kl2PedalClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-pedal.ui");
}

static void
kl2_pedal_init (Kl2Pedal *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
