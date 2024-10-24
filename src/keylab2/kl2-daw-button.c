#include "kl2-daw-button.h"

struct _Kl2DawButton
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2DawButton, kl2_daw_button, SC_TYPE_PREFERENCES_GROUP)

static void
kl2_daw_button_class_init (Kl2DawButtonClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-daw-button.ui");
}

static void
kl2_daw_button_init (Kl2DawButton *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
