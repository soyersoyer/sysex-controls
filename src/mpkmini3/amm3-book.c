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

GtkWidget *
amm3_book_new (void)
{
  return g_object_new(AMM3_TYPE_BOOK, NULL);
}

void
amm3_book_on_arpeggiator_activated (ScNavigationPage *self, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (AMM3_TYPE_ARPEGGIATOR_PAGE, NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
amm3_book_on_joystick_activated (ScNavigationPage *self, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (AMM3_TYPE_JOYSTICK_PAGE, NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
amm3_book_on_keybed_activated (ScNavigationPage *self, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (AMM3_TYPE_KEYBED_PAGE, NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
amm3_book_on_knob_activated (ScNavigationPage *self, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (AMM3_TYPE_KNOB_PAGE, NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
amm3_book_on_pad_activated (ScNavigationPage *self, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (AMM3_TYPE_PAD_PAGE, NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
amm3_book_on_pad_bank_activated (ScNavigationPage *self, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (AMM3_TYPE_PAD_BANK_PAGE,
                                          "control-id-offset", sc_action_row_get_control_id_offset (row),
                                          "title", adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row)),
                                          NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}
