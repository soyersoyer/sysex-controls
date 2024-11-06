#include "kl3-pad.h"

struct _Kl3Pad
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3Pad, kl3_pad, SC_TYPE_PREFERENCES_GROUP)

static void
kl3_pad_class_init (Kl3PadClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-pad.ui");
}

static void
kl3_pad_init (Kl3Pad *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
