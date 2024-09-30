#include "ks37-transport-page.h"

struct _Ks37TransportPage
{
  ScPreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37TransportPage, ks37_transport_page, SC_TYPE_PREFERENCES_PAGE)

static void
ks37_transport_page_class_init (Ks37TransportPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep37/ks37-transport-page.ui");
}

static void
ks37_transport_page_init (Ks37TransportPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

