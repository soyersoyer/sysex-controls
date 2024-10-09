#include "bs-book.h"

struct _BsBook
{
  ScArturiaBook parent_instance;
};

G_DEFINE_FINAL_TYPE (BsBook, bs_book, SC_TYPE_ARTURIA_BOOK)

static void
bs_book_class_init (BsBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-book.ui");
}

static void
bs_book_init (BsBook *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
bs_book_new (snd_seq_t *seq, snd_seq_addr_t addr)
{
  GtkWidget *book = g_object_new (BS_TYPE_BOOK, NULL);
  sc_arturia_book_set_seq (SC_ARTURIA_BOOK (book), seq, addr);
  return book;
}
