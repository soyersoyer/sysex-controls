#include "kles3-book.h"

#include "kles3-button.h"
#include "kles3-button-page.h"
#include "kles3-controller-page.h"
#include "kles3-daw-button.h"
#include "kles3-daw-control-row.h"
#include "kles3-fader.h"
#include "kles3-fader-page.h"
#include "kles3-knob.h"
#include "kles3-knob-page.h"
#include "kles3-led-color.h"
#include "kles3-main-knob-page.h"
#include "kles3-pad.h"
#include "kles3-pad-page.h"
#include "kles3-pedal-page.h"
#include "kles3-pitch-mod-page.h"
#include "kles3-preset-page.h"
#include "kles3-velocity-page.h"

struct _Kles3Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3Book, kles3_book, AR_TYPE_BOOK)

static void
kles3_book_class_init (Kles3BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-book.ui");
}

static void
kles3_book_init (Kles3Book *self)
{
  ArBookClass *scklass = AR_BOOK_GET_CLASS (self);
  scklass->read_control = sc_midi_arturia_v3_read_control;
  scklass->write_control = sc_midi_arturia_v3_write_control;

  g_type_ensure (KLES3_TYPE_BUTTON);
  g_type_ensure (KLES3_TYPE_BUTTON_PAGE);
  g_type_ensure (KLES3_TYPE_CONTROLLER_PAGE);
  g_type_ensure (KLES3_TYPE_DAW_BUTTON);
  g_type_ensure (KLES3_TYPE_DAW_CONTROL_ROW);
  g_type_ensure (KLES3_TYPE_FADER);
  g_type_ensure (KLES3_TYPE_FADER_PAGE);
  g_type_ensure (KLES3_TYPE_KNOB);
  g_type_ensure (KLES3_TYPE_KNOB_PAGE);
  g_type_ensure (KLES3_TYPE_LED_COLOR);
  g_type_ensure (KLES3_TYPE_MAIN_KNOB_PAGE);
  g_type_ensure (KLES3_TYPE_PAD);
  g_type_ensure (KLES3_TYPE_PAD_PAGE);
  g_type_ensure (KLES3_TYPE_PEDAL_PAGE);
  g_type_ensure (KLES3_TYPE_PITCH_MOD_PAGE);
  g_type_ensure (KLES3_TYPE_PRESET_PAGE);
  g_type_ensure (KLES3_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
kles3_book_new (void)
{
  return g_object_new (KLES3_TYPE_BOOK, NULL);
}

static uint32_t
get_preset_offset (ScNavigationPage *page)
{
  // 0x09400100 -> 0x04400000
  uint32_t offset = sc_navigation_page_get_control_id_offset (page);
  return 0x03400000 + (offset << 16);
}

static void
open_preset_page (ScNavigationPage *page, ScActionRow *row, GType type)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (type,
                                          "title", adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row)),
                                          "control-id-offset", get_preset_offset (page),
                                          "control-cc-offset", get_preset_offset (page),
                                          NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
}

void
kles3_book_on_preset_pitch_mod_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KLES3_TYPE_PITCH_MOD_PAGE);
}

void
kles3_book_on_preset_main_knob_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KLES3_TYPE_MAIN_KNOB_PAGE);
}

void
kles3_book_on_preset_knob_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KLES3_TYPE_KNOB_PAGE);
}

void
kles3_book_on_preset_button_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KLES3_TYPE_BUTTON_PAGE);
}

void
kles3_book_on_preset_fader_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KLES3_TYPE_FADER_PAGE);
}

void
kles3_book_on_preset_pad_a_activated (ScNavigationPage *page, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (KLES3_TYPE_PAD_PAGE,
                                          "control-id-offset", get_preset_offset (page),
                                          "control-cc-offset", get_preset_offset (page),
                                          "title", "Pads Bank A",
                                          NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
}

void
kles3_book_on_preset_pad_b_activated (ScNavigationPage *page, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (KLES3_TYPE_PAD_PAGE,
                                          "control-id-offset", get_preset_offset (page) + 0x0800,
                                          "control-cc-offset", get_preset_offset (page) + 0x0100,
                                          "title", "Pads Bank B",
                                          NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
}
