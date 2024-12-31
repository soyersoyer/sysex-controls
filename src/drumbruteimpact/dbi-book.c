#include "dbi-book.h"

#include "dbi-controller-page.h"
#include "dbi-drum-map-page.h"
#include "dbi-global-page.h"
#include "dbi-roller-page.h"
#include "dbi-transport-page.h"

struct _DbiBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (DbiBook, dbi_book, AR_TYPE_BOOK)

static void
dbi_book_class_init (DbiBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/drumbruteimpact/dbi-book.ui");
}

static void
dbi_book_init (DbiBook *self)
{
  g_type_ensure (DBI_TYPE_CONTROLLER_PAGE);
  g_type_ensure (DBI_TYPE_DRUM_MAP_PAGE);
  g_type_ensure (DBI_TYPE_GLOBAL_PAGE);
  g_type_ensure (DBI_TYPE_ROLLER_PAGE);
  g_type_ensure (DBI_TYPE_TRANSPORT_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
dbi_book_new (void)
{
  return g_object_new (DBI_TYPE_BOOK, NULL);
}
