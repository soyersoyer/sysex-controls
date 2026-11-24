#include "nkls-transport-buttons-page.h"

struct _NklsTransportButtonsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NklsTransportButtonsPage, nkls_transport_buttons_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkls_transport_buttons_page_class_init (NklsTransportButtonsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrolstudio/nkls-transport-buttons-page.ui");
}

static void
nkls_transport_buttons_page_init (NklsTransportButtonsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
