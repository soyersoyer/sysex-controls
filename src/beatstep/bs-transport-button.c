#include "bs-transport-button.h"

struct _BsTransportButton
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (BsTransportButton, bs_transport_button, SC_TYPE_PREFERENCES_GROUP)

static void
bs_transport_button_class_init (BsTransportButtonClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-transport-button.ui");
}

static void
bs_transport_button_init (BsTransportButton *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
