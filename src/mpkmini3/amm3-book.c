#include "amm3-book.h"

#include "amm3-arpeggiator-page.h"
#include "amm3-joystick-page.h"
#include "amm3-keybed-page.h"
#include "amm3-knob.h"
#include "amm3-knob-page.h"
#include "amm3-pad.h"
#include "amm3-pad-bank-page.h"
#include "amm3-pad-page.h"
#include "amm3-program-page.h"

struct _Amm3Book
{
  AkBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm3Book, amm3_book, AK_TYPE_BOOK)

static void
amm3_book_class_init (Amm3BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini3/amm3-book.ui");
}

static void
amm3_book_init (Amm3Book *self)
{
  ak_book_set_dev_id (AK_BOOK (self), AKAI_MPK3_ID);
  ak_book_set_query_cmd (AK_BOOK (self), AKAI_CMD_QUERY);
  ak_book_set_recv_cmd (AK_BOOK (self), AKAI_CMD_RECEIVE);
  ak_book_set_send_cmd (AK_BOOK (self), AKAI_CMD_SEND);
  ak_book_set_sel_cmd (AK_BOOK (self), AKAI_CMD_SELECT);

  g_type_ensure (AMM3_TYPE_ARPEGGIATOR_PAGE);
  g_type_ensure (AMM3_TYPE_JOYSTICK_PAGE);
  g_type_ensure (AMM3_TYPE_KEYBED_PAGE);
  g_type_ensure (AMM3_TYPE_KNOB);
  g_type_ensure (AMM3_TYPE_KNOB_PAGE);
  g_type_ensure (AMM3_TYPE_PAD);
  g_type_ensure (AMM3_TYPE_PAD_BANK_PAGE);
  g_type_ensure (AMM3_TYPE_PAD_PAGE);
  g_type_ensure (AMM3_TYPE_PROGRAM_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
