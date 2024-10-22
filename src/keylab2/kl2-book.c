#include "kl2-book.h"

#include "kl2-controller-page.h"

struct _Kl2Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2Book, kl2_book, AR_TYPE_BOOK)

static void
kl2_book_class_init (Kl2BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-book.ui");
}

static void
kl2_book_init (Kl2Book *self)
{
  g_type_ensure (KL2_TYPE_CONTROLLER_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
kl2_book_new (snd_seq_t *seq, snd_seq_addr_t addr)
{
  GtkWidget *book = g_object_new (KL2_TYPE_BOOK, NULL);
  ar_book_set_seq (AR_BOOK (book), seq, addr);
  return book;
}
