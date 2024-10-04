#include "ml3-book.h"

struct _Ml3Book
{
  ScArturiaBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3Book, ml3_book, SC_TYPE_ARTURIA_BOOK)

static void
ml3_book_class_init (Ml3BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-book.ui");
}

static void
ml3_book_init (Ml3Book *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
ml3_book_new (snd_seq_t *seq, snd_seq_addr_t *addr)
{
  GtkWidget *book = g_object_new (ML3_TYPE_BOOK, NULL);
  sc_arturia_book_set_seq (SC_ARTURIA_BOOK (book), seq, addr);
  return book;
}
