#include "nkl1-transport-button-page.h"

struct _Nkl1TransportButtonPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nkl1TransportButtonPage, nkl1_transport_button_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkl1_transport_button_page_class_init (Nkl1TransportButtonPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrol1/nkl1-transport-button-page.ui");
}

static void
nkl1_transport_button_page_init (Nkl1TransportButtonPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
