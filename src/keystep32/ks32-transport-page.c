#include "ks32-transport-page.h"

struct _Ks32TransportPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks32TransportPage, ks32_transport_page, SC_TYPE_NAVIGATION_PAGE)

static void
ks32_transport_page_class_init (Ks32TransportPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep32/ks32-transport-page.ui");
}

static void
ks32_transport_page_init (Ks32TransportPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
