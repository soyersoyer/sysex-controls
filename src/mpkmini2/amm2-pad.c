#include "amm2-pad.h"

struct _Amm2Pad
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm2Pad, amm2_pad, SC_TYPE_PREFERENCES_GROUP)

static void
amm2_pad_class_init (Amm2PadClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini2/amm2-pad.ui");
}

static void
amm2_pad_init (Amm2Pad *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
