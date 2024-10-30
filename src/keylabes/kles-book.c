#include "kles-book.h"

#include "kles-button.h"
#include "kles-button-page.h"
#include "kles-controller-page.h"
#include "kles-fader.h"
#include "kles-fader-page.h"
#include "kles-keyboard-page.h"
#include "kles-knob.h"
#include "kles-knob-page.h"
#include "kles-pad.h"
#include "kles-pad-page.h"
#include "kles-pedal-page.h"
#include "kles-velocity-page.h"

struct _KlesBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesBook, kles_book, AR_TYPE_BOOK)

static void
kles_book_class_init (KlesBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-book.ui");
}

static void
kles_book_init (KlesBook *self)
{
  g_type_ensure (KLES_TYPE_BUTTON);
  g_type_ensure (KLES_TYPE_BUTTON_PAGE);
  g_type_ensure (KLES_TYPE_CONTROLLER_PAGE);
  g_type_ensure (KLES_TYPE_FADER);
  g_type_ensure (KLES_TYPE_FADER_PAGE);
  g_type_ensure (KLES_TYPE_KEYBOARD_PAGE);
  g_type_ensure (KLES_TYPE_KNOB);
  g_type_ensure (KLES_TYPE_KNOB_PAGE);
  g_type_ensure (KLES_TYPE_PAD);
  g_type_ensure (KLES_TYPE_PAD_PAGE);
  g_type_ensure (KLES_TYPE_PEDAL_PAGE);
  g_type_ensure (KLES_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
kles_book_new (snd_seq_t *seq, snd_seq_addr_t addr)
{
  GtkWidget *book = g_object_new (KLES_TYPE_BOOK, NULL);
  sc_book_set_seq (SC_BOOK (book), seq, addr);
  return book;
}
