#include "ks32-book.h"

#include "ks32-controller-page.h"
#include "ks32-cv-gate-page.h"
#include "ks32-hold-switch-page.h"
#include "ks32-mod-pitch-page.h"
#include "ks32-sequence-page.h"
#include "ks32-sustain-pedal-page.h"
#include "ks32-transport-page.h"

struct _Ks32Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks32Book, ks32_book, AR_TYPE_BOOK)

static void
ks32_book_class_init (Ks32BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep32/ks32-book.ui");
}

static void
ks32_book_init (Ks32Book *self)
{
  ar_book_set_read_ack (AR_BOOK (self), true);

  g_type_ensure (KS32_TYPE_CONTROLLER_PAGE);
  g_type_ensure (KS32_TYPE_CV_GATE_PAGE);
  g_type_ensure (KS32_TYPE_HOLD_SWITCH_PAGE);
  g_type_ensure (KS32_TYPE_MOD_PITCH_PAGE);
  g_type_ensure (KS32_TYPE_SEQUENCE_PAGE);
  g_type_ensure (KS32_TYPE_SUSTAIN_PEDAL_PAGE);
  g_type_ensure (KS32_TYPE_TRANSPORT_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
ks32_book_new (snd_seq_t *seq, snd_seq_addr_t addr)
{
  GtkWidget *book = g_object_new (KS32_TYPE_BOOK, NULL);
  sc_book_set_seq (SC_BOOK (book), seq, addr);
  return book;
}
