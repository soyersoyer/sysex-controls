#include "ks37-page-transport.h"

struct _Ks37PageTransport
{
  AdwPreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37PageTransport, ks37_page_transport, ADW_TYPE_PREFERENCES_PAGE)

static void
ks37_page_transport_class_init (Ks37PageTransportClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/keystep37-settings/pages/transport/ks37-page-transport.ui");
}

static void
ks37_page_transport_init (Ks37PageTransport *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

