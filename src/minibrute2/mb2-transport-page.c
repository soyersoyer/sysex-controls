#include "mb2-transport-page.h"

struct _Mb2TransportPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mb2TransportPage, mb2_transport_page, SC_TYPE_NAVIGATION_PAGE)

static void
mb2_transport_page_class_init (Mb2TransportPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minibrute2/mb2-transport-page.ui");
}

static void
mb2_transport_page_init (Mb2TransportPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
