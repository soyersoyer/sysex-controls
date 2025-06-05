#include "nkl2-transport-buttons-page.h"

struct _Nkl2TransportButtonsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nkl2TransportButtonsPage, nkl2_transport_buttons_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkl2_transport_buttons_page_class_init (Nkl2TransportButtonsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrol2/nkl2-transport-buttons-page.ui");
}

static void
nkl2_transport_buttons_page_init (Nkl2TransportButtonsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
