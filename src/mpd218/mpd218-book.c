#include "mpd218-book.h"

#include "mpd218-knob-bank-page.h"
#include "mpd218-knob-page.h"
#include "mpd218-note-repeat-page.h"
#include "mpd218-pad-bank-page.h"
#include "mpd218-pad-page.h"
#include "mpd218-program-page.h"

struct _Mpd218Book
{
  AkBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Mpd218Book, mpd218_book, AK_TYPE_BOOK)

static void
mpd218_book_class_init (Mpd218BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpd218/mpd218-book.ui");
}

static void
mpd218_book_init (Mpd218Book *self)
{
  ak_book_set_dev_id (AK_BOOK (self), AKAI_MPD218_ID);
  ak_book_set_query_cmd (AK_BOOK (self), AKAI_MPD218_CMD_QUERY);
  ak_book_set_recv_cmd (AK_BOOK (self), AKAI_MPD218_CMD_RECEIVE);
  ak_book_set_send_cmd (AK_BOOK (self), AKAI_MPD218_CMD_SEND);

  g_type_ensure (MPD218_TYPE_KNOB_BANK_PAGE);
  g_type_ensure (MPD218_TYPE_KNOB_PAGE);
  g_type_ensure (MPD218_TYPE_NOTE_REPEAT_PAGE);
  g_type_ensure (MPD218_TYPE_PAD_BANK_PAGE);
  g_type_ensure (MPD218_TYPE_PAD_PAGE);
  g_type_ensure (MPD218_TYPE_PROGRAM_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
