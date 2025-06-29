#include "amm-book.h"

#include "amm-arpeggiator-page.h"
#include "amm-keybed-page.h"
#include "amm-knob.h"
#include "amm-knob-page.h"
#include "amm-pad.h"
#include "amm-pad-bank-page.h"
#include "amm-pad-page.h"
#include "amm-program-page.h"

struct _AmmBook
{
  AkBook parent_instance;
};

G_DEFINE_FINAL_TYPE (AmmBook, amm_book, AK_TYPE_BOOK)

static void
amm_book_class_init (AmmBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini/amm-book.ui");
}

static void
amm_book_init (AmmBook *self)
{
  ak_book_set_dev_id (AK_BOOK (self), AKAI_MPK1_ID);
  ak_book_set_query_cmd (AK_BOOK (self), AKAI_CMD_V1_QUERY);
  ak_book_set_recv_cmd (AK_BOOK (self), AKAI_CMD_V1_RECEIVE);
  ak_book_set_send_cmd (AK_BOOK (self), AKAI_CMD_V1_SEND);
  ak_book_set_sel_cmd (AK_BOOK (self), AKAI_CMD_SELECT);

  g_type_ensure (AMM_TYPE_ARPEGGIATOR_PAGE);
  g_type_ensure (AMM_TYPE_KEYBED_PAGE);
  g_type_ensure (AMM_TYPE_KNOB);
  g_type_ensure (AMM_TYPE_KNOB_PAGE);
  g_type_ensure (AMM_TYPE_PAD);
  g_type_ensure (AMM_TYPE_PAD_BANK_PAGE);
  g_type_ensure (AMM_TYPE_PAD_PAGE);
  g_type_ensure (AMM_TYPE_PROGRAM_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
