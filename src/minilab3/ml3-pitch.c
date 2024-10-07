#include "ml3-pitch.h"

struct _Ml3Pitch
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3Pitch, ml3_pitch, SC_TYPE_PREFERENCES_GROUP)

static void
ml3_pitch_class_init (Ml3PitchClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-pitch.ui");
}

static void
ml3_pitch_init (Ml3Pitch *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
