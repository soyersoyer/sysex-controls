#include "ml2-book.h"

#include "ml2-color-row.h"
#include "ml2-pad.h"
#include "ml2-pad-bank.h"

struct _Ml2Book
{
  ScArturiaBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2Book, ml2_book, SC_TYPE_ARTURIA_BOOK)

static void
ml2_book_class_init (Ml2BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-book.ui");
}

static void
ml2_book_init (Ml2Book *self)
{
  g_type_ensure (ML2_TYPE_COLOR_ROW);
  g_type_ensure (ML2_TYPE_PAD);
  g_type_ensure (ML2_TYPE_PAD_BANK);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
ml2_book_new (snd_seq_t *seq, snd_seq_addr_t *addr)
{
  GtkWidget *book = g_object_new (ML2_TYPE_BOOK, NULL);
  sc_arturia_book_set_seq (SC_ARTURIA_BOOK (book), seq, addr);
  return book;
}
