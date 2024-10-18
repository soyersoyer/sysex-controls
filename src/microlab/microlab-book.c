#include "microlab-book.h"

#include "microlab-ch-row.h"
#include "microlab-hold-page.h"
#include "microlab-keyboard-page.h"
#include "microlab-mod-page.h"
#include "microlab-pitch-page.h"

struct _MicrolabBook
{
  ScArturiaBook parent_instance;
};

G_DEFINE_FINAL_TYPE (MicrolabBook, microlab_book, SC_TYPE_ARTURIA_BOOK)

static void
microlab_book_class_init (MicrolabBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/microlab/microlab-book.ui");
}

static void
microlab_book_init (MicrolabBook *self)
{
  g_type_ensure (MICROLAB_TYPE_CH_ROW);
  g_type_ensure (MICROLAB_TYPE_HOLD_PAGE);
  g_type_ensure (MICROLAB_TYPE_KEYBOARD_PAGE);
  g_type_ensure (MICROLAB_TYPE_MOD_PAGE);
  g_type_ensure (MICROLAB_TYPE_PITCH_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
microlab_book_new (snd_seq_t *seq, snd_seq_addr_t addr)
{
  GtkWidget *book = g_object_new (MICROLAB_TYPE_BOOK, NULL);
  sc_arturia_book_set_seq (SC_ARTURIA_BOOK (book), seq, addr);
  return book;
}
