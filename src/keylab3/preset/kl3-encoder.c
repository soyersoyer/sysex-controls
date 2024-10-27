#include "kl3-encoder.h"

struct _Kl3Encoder
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3Encoder, kl3_encoder, SC_TYPE_PREFERENCES_GROUP)

static void
kl3_encoder_class_init (Kl3EncoderClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/preset/kl3-encoder.ui");
}

static void
kl3_encoder_init (Kl3Encoder *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
