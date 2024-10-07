#include "ml3-fader.h"

struct _Ml3Fader
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3Fader, ml3_fader, SC_TYPE_PREFERENCES_GROUP)

static void
ml3_fader_class_init (Ml3FaderClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-fader.ui");
}

static void
ml3_fader_init (Ml3Fader *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
