#include "bsp-pad.h"

struct _BspPad
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (BspPad, bsp_pad, SC_TYPE_PREFERENCES_GROUP)

static void
bsp_pad_class_init (BspPadClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-pad.ui");
}

static void
bsp_pad_init (BspPad *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
