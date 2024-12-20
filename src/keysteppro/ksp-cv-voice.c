#include "ksp-cv-voice.h"

struct _KspCvVoice
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (KspCvVoice, ksp_cv_voice, SC_TYPE_PREFERENCES_GROUP)

static void
ksp_cv_voice_class_init (KspCvVoiceClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keysteppro/ksp-cv-voice.ui");
}

static void
ksp_cv_voice_init (KspCvVoice *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
