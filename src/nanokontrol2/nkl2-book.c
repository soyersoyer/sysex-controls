#include "nkl2-book.h"

#include "nkl2-button-page.h"
#include "nkl2-controller-group-page.h"
#include "nkl2-controller-groups-page.h"
#include "nkl2-function-button-page.h"
#include "nkl2-knob-page.h"
#include "nkl2-scene-page.h"
#include "nkl2-slider-page.h"
#include "nkl2-transport-buttons-page.h"

struct _Nkl2Book
{
  KorgBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Nkl2Book, nkl2_book, KORG_TYPE_BOOK)

static void
nkl2_book_class_init (Nkl2BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrol2/nkl2-book.ui");
}

static void
nkl2_book_init (Nkl2Book *self)
{
  const uint8_t nkl2_dev_id[4] ={0x00, 0x01, 0x13, 0x00};
  korg_book_set_dev_id (KORG_BOOK (self), nkl2_dev_id);

  g_type_ensure (NKL2_TYPE_BUTTON_PAGE);
  g_type_ensure (NKL2_TYPE_CONTROLLER_GROUP_PAGE);
  g_type_ensure (NKL2_TYPE_CONTROLLER_GROUPS_PAGE);
  g_type_ensure (NKL2_TYPE_FUNCTION_BUTTON_PAGE);
  g_type_ensure (NKL2_TYPE_KNOB_PAGE);
  g_type_ensure (NKL2_TYPE_SCENE_PAGE);
  g_type_ensure (NKL2_TYPE_SLIDER_PAGE);
  g_type_ensure (NKL2_TYPE_TRANSPORT_BUTTONS_PAGE);


  gtk_widget_init_template (GTK_WIDGET (self));
}

static void
push_page (ScNavigationPage *page, ScActionRow *row, GType type)
{
  uint32_t control_id_offset = sc_navigation_page_get_control_id_offset (page) + sc_action_row_get_control_id_offset (row);
  uint32_t control_cc_offset = sc_navigation_page_get_control_cc_offset (page) + sc_action_row_get_control_cc_offset (row);
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (type,
                                          "title", adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row)),
                                          "control-id-offset", control_id_offset,
                                          "control-cc-offset", control_cc_offset,
                                          NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
}

void
nkl2_book_on_button_activated (ScNavigationPage *page, ScActionRow* row)
{
  push_page (page, row, NKL2_TYPE_BUTTON_PAGE);
}

void
nkl2_book_on_controller_group_activated (ScNavigationPage *page, ScActionRow* row)
{
  push_page (page, row, NKL2_TYPE_CONTROLLER_GROUP_PAGE);
}

void
nkl2_book_on_controller_groups_activated (ScNavigationPage *page, ScActionRow* row)
{
  push_page (page, row, NKL2_TYPE_CONTROLLER_GROUPS_PAGE);
}

void
nkl2_book_on_function_button_activated (ScNavigationPage *page, ScActionRow* row)
{
  push_page (page, row, NKL2_TYPE_FUNCTION_BUTTON_PAGE);
}

void
nkl2_book_on_knob_activated (ScNavigationPage *page, ScActionRow* row)
{
  push_page (page, row, NKL2_TYPE_KNOB_PAGE);
}

void
nkl2_book_on_slider_activated (ScNavigationPage *page, ScActionRow* row)
{
  push_page (page, row, NKL2_TYPE_SLIDER_PAGE);
}

void
nkl2_book_on_transport_buttons_activated (ScNavigationPage *page, ScActionRow* row)
{
  push_page (page, row, NKL2_TYPE_TRANSPORT_BUTTONS_PAGE);
}
