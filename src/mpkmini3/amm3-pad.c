#include "amm3-pad.h"

struct _Amm3Pad
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm3Pad, amm3_pad, SC_TYPE_PREFERENCES_GROUP)

static void
amm3_pad_class_init (Amm3PadClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini3/amm3-pad.ui");
}

static void
amm3_pad_init (Amm3Pad *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
