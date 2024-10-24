#include "kl2-pad.h"

struct _Kl2Pad
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2Pad, kl2_pad, SC_TYPE_PREFERENCES_GROUP)

static void
kl2_pad_class_init (Kl2PadClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-pad.ui");
}

static void
kl2_pad_init (Kl2Pad *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
