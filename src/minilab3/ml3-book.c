#include "ml3-book.h"

#include "ml3-fader.h"
#include "ml3-knob.h"
#include "ml3-main-knob.h"
#include "ml3-main-knob-click.h"
#include "ml3-mod.h"
#include "ml3-pad.h"
#include "ml3-pad-bank.h"
#include "ml3-pitch.h"
#include "ml3-shift.h"

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
  ScArturiaBookClass *scklass = SC_ARTURIA_BOOK_GET_CLASS (self);
  scklass->read_control = sc_midi_arturia_v3_read_control;
  scklass->write_control = sc_midi_arturia_v3_write_control;

  g_type_ensure (ML3_TYPE_FADER);
  g_type_ensure (ML3_TYPE_KNOB);
  g_type_ensure (ML3_TYPE_MAIN_KNOB);
  g_type_ensure (ML3_TYPE_MAIN_KNOB_CLICK);
  g_type_ensure (ML3_TYPE_MOD);
  g_type_ensure (ML3_TYPE_PAD);
  g_type_ensure (ML3_TYPE_PAD_BANK);
  g_type_ensure (ML3_TYPE_PITCH);
  g_type_ensure (ML3_TYPE_SHIFT);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
ml3_book_new (snd_seq_t *seq, snd_seq_addr_t *addr)
{
  GtkWidget *book = g_object_new (ML3_TYPE_BOOK, NULL);
  sc_arturia_book_set_seq (SC_ARTURIA_BOOK (book), seq, addr);
  return book;
}
