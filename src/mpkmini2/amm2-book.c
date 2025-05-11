#include "amm2-book.h"

#include "amm2-arpeggiator-page.h"
#include "amm2-joystick-page.h"
#include "amm2-keybed-page.h"
#include "amm2-knob.h"
#include "amm2-knob-page.h"
#include "amm2-pad.h"
#include "amm2-pad-bank-page.h"
#include "amm2-pad-page.h"
#include "amm2-program-page.h"

struct _Amm2Book
{
  AkBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm2Book, amm2_book, AK_TYPE_BOOK)

static void
amm2_book_class_init (Amm2BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini2/amm2-book.ui");
}

static void
amm2_book_init (Amm2Book *self)
{
  ak_book_set_dev_id (AK_BOOK (self), AKAI_MPK2_ID);
  ak_book_set_query_cmd (AK_BOOK (self), AKAI_CMD_QUERY);
  ak_book_set_recv_cmd (AK_BOOK (self), AKAI_CMD_RECEIVE);
  ak_book_set_send_cmd (AK_BOOK (self), AKAI_CMD_SEND);
  ak_book_set_sel_cmd (AK_BOOK (self), AKAI_CMD_SELECT);

  g_type_ensure (AMM2_TYPE_ARPEGGIATOR_PAGE);
  g_type_ensure (AMM2_TYPE_JOYSTICK_PAGE);
  g_type_ensure (AMM2_TYPE_KEYBED_PAGE);
  g_type_ensure (AMM2_TYPE_KNOB);
  g_type_ensure (AMM2_TYPE_KNOB_PAGE);
  g_type_ensure (AMM2_TYPE_PAD);
  g_type_ensure (AMM2_TYPE_PAD_BANK_PAGE);
  g_type_ensure (AMM2_TYPE_PAD_PAGE);
  g_type_ensure (AMM2_TYPE_PROGRAM_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

void
amm2_book_on_arpeggiator_activated (ScNavigationPage *self, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (AMM2_TYPE_ARPEGGIATOR_PAGE, NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
amm2_book_on_joystick_activated (ScNavigationPage *self, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (AMM2_TYPE_JOYSTICK_PAGE, NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
amm2_book_on_keybed_activated (ScNavigationPage *self, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (AMM2_TYPE_KEYBED_PAGE, NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
amm2_book_on_knob_activated (ScNavigationPage *self, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (AMM2_TYPE_KNOB_PAGE, NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
amm2_book_on_pad_activated (ScNavigationPage *self, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (AMM2_TYPE_PAD_PAGE, NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
amm2_book_on_pad_bank_activated (ScNavigationPage *self, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (AMM2_TYPE_PAD_BANK_PAGE,
                                          "control-id-offset", sc_action_row_get_control_id_offset (row),
                                          "title", adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row)),
                                          NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}
