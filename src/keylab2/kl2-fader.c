#include "kl2-fader.h"

struct _Kl2Fader
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2Fader, kl2_fader, SC_TYPE_PREFERENCES_GROUP)

static void
kl2_fader_class_init (Kl2FaderClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-fader.ui");
}

static void
kl2_fader_init (Kl2Fader *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
