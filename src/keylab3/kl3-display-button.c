#include "kl3-display-button.h"

struct _Kl3DisplayButton
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3DisplayButton, kl3_display_button, SC_TYPE_PREFERENCES_GROUP)

static void
kl3_display_button_class_init (Kl3DisplayButtonClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-display-button.ui");
}

static void
kl3_display_button_init (Kl3DisplayButton *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
