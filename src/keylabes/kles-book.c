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
#include "kles-preset-page.h"
#include "kles-presets-page.h"
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
  ar_book_set_preset_sync (AR_BOOK (self), true);

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
  g_type_ensure (KLES_TYPE_PRESET_PAGE);
  g_type_ensure (KLES_TYPE_PRESETS_PAGE);
  g_type_ensure (KLES_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

static void
open_preset_page (ScNavigationPage *page, ScActionRow *row, GType type)
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
kles_book_on_presets_preset_activated (ScNavigationPage *page, ScActionRow *row)
{
  open_preset_page (page, row, KLES_TYPE_PRESET_PAGE);
}

void
kles_book_on_preset_keyboard_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KLES_TYPE_KEYBOARD_PAGE);
}

void
kles_book_on_preset_pedal_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KLES_TYPE_PEDAL_PAGE);
}

void
kles_book_on_preset_pad_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KLES_TYPE_PAD_PAGE);
}

void
kles_book_on_preset_button_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KLES_TYPE_BUTTON_PAGE);
}

void
kles_book_on_preset_knob_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KLES_TYPE_KNOB_PAGE);
}

void
kles_book_on_preset_fader_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KLES_TYPE_FADER_PAGE);
}
