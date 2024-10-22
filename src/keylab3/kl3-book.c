#include "kl3-book.h"

#include "kl3-controller-page.h"

struct _Kl3Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3Book, kl3_book, AR_TYPE_BOOK)

static void
kl3_book_class_init (Kl3BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-book.ui");
}

static void
kl3_book_init (Kl3Book *self)
{
  ArBookClass *scklass = AR_BOOK_GET_CLASS (self);
  scklass->read_control = sc_midi_arturia_v3_read_control;
  scklass->write_control = sc_midi_arturia_v3_write_control;

  g_type_ensure (KL3_TYPE_CONTROLLER_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
kl3_book_new (snd_seq_t *seq, snd_seq_addr_t addr)
{
  GtkWidget *book = g_object_new (KL3_TYPE_BOOK, NULL);
  ar_book_set_seq (AR_BOOK (book), seq, addr);
  return book;
}
