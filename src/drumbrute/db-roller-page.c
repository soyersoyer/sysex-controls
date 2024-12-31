#include "db-roller-page.h"

struct _DbRollerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (DbRollerPage, db_roller_page, SC_TYPE_NAVIGATION_PAGE)

static void
db_roller_page_class_init (DbRollerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/drumbrute/db-roller-page.ui");
}

static void
db_roller_page_init (DbRollerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
