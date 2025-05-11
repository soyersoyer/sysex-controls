#include "amm-pad.h"

struct _AmmPad
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (AmmPad, amm_pad, SC_TYPE_PREFERENCES_GROUP)

static void
amm_pad_class_init (AmmPadClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini/amm-pad.ui");
}

static void
amm_pad_init (AmmPad *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
