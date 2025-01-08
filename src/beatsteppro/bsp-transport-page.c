#include "bsp-transport-page.h"

struct _BspTransportPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspTransportPage, bsp_transport_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_transport_page_class_init (BspTransportPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-transport-page.ui");
}

static void
bsp_transport_page_init (BspTransportPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
