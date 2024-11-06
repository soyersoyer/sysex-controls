#include "kles3-button.h"

struct _Kles3Button
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3Button, kles3_button, SC_TYPE_PREFERENCES_GROUP)

static void
kles3_button_class_init (Kles3ButtonClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-button.ui");
}

static void
kles3_button_init (Kles3Button *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
