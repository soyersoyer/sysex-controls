#include "matr-book.h"

#include "matr-channels-page.h"

struct _MatrBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (MatrBook, matr_book, AR_TYPE_BOOK)

static void
matr_book_class_init (MatrBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/matriarch/matr-book.ui");
}

static void
matr_book_init (MatrBook *self)
{
  ar_book_set_read_ack (AR_BOOK (self), true);

  g_type_ensure (MATR_TYPE_CHANNELS_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
