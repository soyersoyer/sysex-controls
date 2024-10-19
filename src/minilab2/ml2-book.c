#include "ml2-book.h"

#include "ml2-button.h"
#include "ml2-ch-row.h"
#include "ml2-global-page.h"
#include "ml2-knob.h"
#include "ml2-knob-extra-page.h"
#include "ml2-knob-page.h"
#include "ml2-mod-wheel-page.h"
#include "ml2-pad.h"
#include "ml2-pad-page.h"
#include "ml2-pitch-bend-page.h"
#include "ml2-sustain-pedal-page.h"

struct _Ml2Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2Book, ml2_book, AR_TYPE_BOOK)

static void
ml2_book_class_init (Ml2BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-book.ui");
}

static void
ml2_book_init (Ml2Book *self)
{
  g_type_ensure (ML2_TYPE_BUTTON);
  g_type_ensure (ML2_TYPE_CH_ROW);
  g_type_ensure (ML2_TYPE_GLOBAL_PAGE);
  g_type_ensure (ML2_TYPE_KNOB);
  g_type_ensure (ML2_TYPE_KNOB_EXTRA_PAGE);
  g_type_ensure (ML2_TYPE_KNOB_PAGE);
  g_type_ensure (ML2_TYPE_MOD_WHEEL_PAGE);
  g_type_ensure (ML2_TYPE_PAD);
  g_type_ensure (ML2_TYPE_PAD_PAGE);
  g_type_ensure (ML2_TYPE_PITCH_BEND_PAGE);
  g_type_ensure (ML2_TYPE_SUSTAIN_PEDAL_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
ml2_book_new (snd_seq_t *seq, snd_seq_addr_t addr)
{
  GtkWidget *book = g_object_new (ML2_TYPE_BOOK, NULL);
  ar_book_set_seq (AR_BOOK (book), seq, addr);
  return book;
}
