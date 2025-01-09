#include "db-book.h"

#include "db-controller-page.h"
#include "db-drum-map-page.h"
#include "db-global-page.h"
#include "db-roller-page.h"
#include "db-transport-page.h"

struct _DbBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (DbBook, db_book, AR_TYPE_BOOK)

static void
db_book_class_init (DbBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/drumbrute/db-book.ui");
}

static void
db_book_init (DbBook *self)
{
  g_type_ensure (DB_TYPE_CONTROLLER_PAGE);
  g_type_ensure (DB_TYPE_DRUM_MAP_PAGE);
  g_type_ensure (DB_TYPE_GLOBAL_PAGE);
  g_type_ensure (DB_TYPE_ROLLER_PAGE);
  g_type_ensure (DB_TYPE_TRANSPORT_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
