#include "kles3-led-color.h"

struct _Kles3LedColor
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3LedColor, kles3_led_color, SC_TYPE_PREFERENCES_GROUP)

static void
kles3_led_color_class_init (Kles3LedColorClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/preset/kles3-led-color.ui");
}

static void
kles3_led_color_init (Kles3LedColor *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
