#include "bs-book.h"

#include "bs-ch-row.h"
#include "bs-controller-page.h"
#include "bs-performance-page.h"
#include "bs-sequence-page.h"

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
  g_type_ensure(BS_TYPE_CH_ROW);
  g_type_ensure(BS_TYPE_CONTROLLER_PAGE);
  g_type_ensure(BS_TYPE_PERFORMANCE_PAGE);
  g_type_ensure(BS_TYPE_SEQUENCE_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
bs_book_new (snd_seq_t *seq, snd_seq_addr_t addr)
{
  GtkWidget *book = g_object_new (BS_TYPE_BOOK, NULL);
  sc_arturia_book_set_seq (SC_ARTURIA_BOOK (book), seq, addr);
  return book;
}
