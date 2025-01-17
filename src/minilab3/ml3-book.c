#include "ml3-book.h"

#include "ml3-controller-page.h"
#include "ml3-fader.h"
#include "ml3-fader-page.h"
#include "ml3-knob.h"
#include "ml3-knob-page.h"
#include "ml3-main-knob.h"
#include "ml3-main-knob-click.h"
#include "ml3-main-knob-page.h"
#include "ml3-pad.h"
#include "ml3-pad-page.h"
#include "ml3-pedal-page.h"
#include "ml3-pitch-mod-page.h"
#include "ml3-preset-page.h"
#include "ml3-presets-page.h"
#include "ml3-spm-page.h"
#include "ml3-velocity-page.h"

struct _Ml3Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3Book, ml3_book, AR_TYPE_BOOK)

static void
ml3_book_class_init (Ml3BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-book.ui");
}

static void
ml3_book_init (Ml3Book *self)
{
  ArBookClass *scklass = AR_BOOK_GET_CLASS (self);
  scklass->read_control = sc_midi_arturia_v3_read_control;
  scklass->write_control = sc_midi_arturia_v3_write_control;
  scklass->read_string = sc_midi_arturia_dummy_read_string;

  g_type_ensure (ML3_TYPE_CONTROLLER_PAGE);
  g_type_ensure (ML3_TYPE_FADER);
  g_type_ensure (ML3_TYPE_FADER_PAGE);
  g_type_ensure (ML3_TYPE_KNOB);
  g_type_ensure (ML3_TYPE_KNOB_PAGE);
  g_type_ensure (ML3_TYPE_MAIN_KNOB);
  g_type_ensure (ML3_TYPE_MAIN_KNOB_CLICK);
  g_type_ensure (ML3_TYPE_MAIN_KNOB_PAGE);
  g_type_ensure (ML3_TYPE_PAD);
  g_type_ensure (ML3_TYPE_PAD_PAGE);
  g_type_ensure (ML3_TYPE_PEDAL_PAGE);
  g_type_ensure (ML3_TYPE_PITCH_MOD_PAGE);
  g_type_ensure (ML3_TYPE_PRESET_PAGE);
  g_type_ensure (ML3_TYPE_PRESETS_PAGE);
  g_type_ensure (ML3_TYPE_SPM_PAGE);
  g_type_ensure (ML3_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

void
ml3_book_on_presets_preset_activated (ScNavigationPage *page, ScActionRow *row)
{
  uint32_t control_id_offset = sc_action_row_get_control_id_offset (row);
  uint32_t control_cc_offset = sc_action_row_get_control_cc_offset (row);
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (ML3_TYPE_PRESET_PAGE,
                                          "title", adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row)),
                                          "control-id-offset", control_id_offset,
                                          "control-cc-offset", control_cc_offset,
                                          NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
}

static uint32_t
get_preset_offset (ScNavigationPage *self)
{
  // 0x08400100 -> 0x04400000
  uint32_t offset = sc_navigation_page_get_control_id_offset (self);
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
ml3_book_on_preset_spm_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, ML3_TYPE_SPM_PAGE);
}

void
ml3_book_on_preset_main_knob_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, ML3_TYPE_MAIN_KNOB_PAGE);
}

void
ml3_book_on_preset_knob_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, ML3_TYPE_KNOB_PAGE);
}

void
ml3_book_on_preset_fader_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, ML3_TYPE_FADER_PAGE);
}

void
ml3_book_on_preset_pad_a_activated (ScNavigationPage *self, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (ML3_TYPE_PAD_PAGE,
                                          "control-id-offset", get_preset_offset (self),
                                          "control-cc-offset", get_preset_offset (self),
                                          "title", "Pads Bank A",
                                          NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
ml3_book_on_preset_pad_b_activated (ScNavigationPage *self, ScActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (ML3_TYPE_PAD_PAGE,
                                          "control-id-offset", get_preset_offset (self) + 0x0800,
                                          "control-cc-offset", get_preset_offset (self) + 0x0100,
                                          "title", "Pads Bank B",
                                          NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}
