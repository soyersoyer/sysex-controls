#include "bs-transport-button-page.h"

struct _BsTransportButtonPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BsTransportButtonPage, bs_transport_button_page, SC_TYPE_NAVIGATION_PAGE)

static void
bs_transport_button_page_class_init (BsTransportButtonPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-transport-button-page.ui");
}

static void
bs_transport_button_page_init (BsTransportButtonPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
