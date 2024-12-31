#include "db-global-page.h"

struct _DbGlobalPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (DbGlobalPage, db_global_page, SC_TYPE_NAVIGATION_PAGE)

static void
db_global_page_class_init (DbGlobalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/drumbrute/db-global-page.ui");
}

static void
db_global_page_init (DbGlobalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
