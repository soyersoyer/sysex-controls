#include "dbi-transport-page.h"

struct _DbiTransportPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (DbiTransportPage, dbi_transport_page, SC_TYPE_NAVIGATION_PAGE)

static void
dbi_transport_page_class_init (DbiTransportPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/drumbruteimpact/dbi-transport-page.ui");
}

static void
dbi_transport_page_init (DbiTransportPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
