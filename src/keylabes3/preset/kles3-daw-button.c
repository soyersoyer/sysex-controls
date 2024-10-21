#include "kles3-daw-button.h"

struct _Kles3DawButton
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3DawButton, kles3_daw_button, SC_TYPE_PREFERENCES_GROUP)

static void
kles3_daw_button_class_init (Kles3DawButtonClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/preset/kles3-daw-button.ui");
}

static void
kles3_daw_button_init (Kles3DawButton *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
