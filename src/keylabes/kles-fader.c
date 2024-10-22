#include "kles-fader.h"

struct _KlesFader
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesFader, kles_fader, SC_TYPE_PREFERENCES_GROUP)

static void
kles_fader_class_init (KlesFaderClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-fader.ui");
}

static void
kles_fader_init (KlesFader *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
