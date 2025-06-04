#include "nk2-book.h"

#include "nk2-button-page.h"
#include "nk2-global-page.h"
#include "nk2-keyboard-page.h"
#include "nk2-pitch-bend-page.h"

struct _Nk2Book
{
  KorgBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Nk2Book, nk2_book, KORG_TYPE_BOOK)

static void
nk2_book_class_init (Nk2BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokey2/nk2-book.ui");
}

static void
nk2_book_init (Nk2Book *self)
{
  const uint8_t nk2_dev_id[4] ={0x00, 0x01, 0x11, 0x01};
  korg_book_set_dev_id (KORG_BOOK (self), nk2_dev_id);

  g_type_ensure (NK2_TYPE_BUTTON_PAGE);
  g_type_ensure (NK2_TYPE_GLOBAL_PAGE);
  g_type_ensure (NK2_TYPE_KEYBOARD_PAGE);
  g_type_ensure (NK2_TYPE_PITCH_BEND_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

void
nk2_book_on_button_activated (ScNavigationPage *page, ScActionRow* row)
{
  uint32_t control_id_offset = sc_navigation_page_get_control_id_offset (page) + sc_action_row_get_control_id_offset (row);
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (NK2_TYPE_BUTTON_PAGE,
                                          "title", adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row)),
                                          "control-id-offset", control_id_offset,
                                          NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
};

void
nk2_book_on_keyboard_activated (ScNavigationPage *page, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (NK2_TYPE_KEYBOARD_PAGE, NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
}

void
nk2_book_on_pitch_bend_activated (ScNavigationPage *page, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (NK2_TYPE_PITCH_BEND_PAGE, NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
}
