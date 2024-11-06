#include "kl3-fader.h"

struct _Kl3Fader
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3Fader, kl3_fader, SC_TYPE_PREFERENCES_GROUP)

static void
kl3_fader_class_init (Kl3FaderClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-fader.ui");
}

static void
kl3_fader_init (Kl3Fader *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
