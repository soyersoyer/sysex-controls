#include "kles3-pad.h"

struct _Kles3Pad
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3Pad, kles3_pad, SC_TYPE_PREFERENCES_GROUP)

static void
kles3_pad_class_init (Kles3PadClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-pad.ui");
}

static void
kles3_pad_init (Kles3Pad *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
