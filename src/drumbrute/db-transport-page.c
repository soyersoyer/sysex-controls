#include "db-transport-page.h"

struct _DbTransportPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (DbTransportPage, db_transport_page, SC_TYPE_NAVIGATION_PAGE)

static void
db_transport_page_class_init (DbTransportPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/drumbrute/db-transport-page.ui");
}

static void
db_transport_page_init (DbTransportPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
