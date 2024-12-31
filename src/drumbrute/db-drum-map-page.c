#include "db-drum-map-page.h"

struct _DbDrumMapPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (DbDrumMapPage, db_drum_map_page, SC_TYPE_NAVIGATION_PAGE)

static void
db_drum_map_page_class_init (DbDrumMapPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/drumbrute/db-drum-map-page.ui");
}

static void
db_drum_map_page_init (DbDrumMapPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
