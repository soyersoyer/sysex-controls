#include "ml2-book.h"

#include "ar-preset-page.h"

#include "ml2-button.h"
#include "ml2-controller-page.h"
#include "ml2-knob.h"
#include "ml2-knob-extra-page.h"
#include "ml2-knob-page.h"
#include "ml2-pad.h"
#include "ml2-pad-page.h"
#include "ml2-pedal-page.h"
#include "ml2-pitch-mod-page.h"
#include "ml2-preset-page.h"
#include "ml2-presets-page.h"
#include "ml2-velocity-page.h"

struct _Ml2Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2Book, ml2_book, AR_TYPE_BOOK)

static void
ml2_book_class_init (Ml2BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-book.ui");
}

static void
ml2_book_init (Ml2Book *self)
{
  g_type_ensure (ML2_TYPE_BUTTON);
  g_type_ensure (ML2_TYPE_CONTROLLER_PAGE);
  g_type_ensure (ML2_TYPE_KNOB);
  g_type_ensure (ML2_TYPE_KNOB_EXTRA_PAGE);
  g_type_ensure (ML2_TYPE_KNOB_PAGE);
  g_type_ensure (ML2_TYPE_PAD);
  g_type_ensure (ML2_TYPE_PAD_PAGE);
  g_type_ensure (ML2_TYPE_PEDAL_PAGE);
  g_type_ensure (ML2_TYPE_PITCH_MOD_PAGE);
  g_type_ensure (ML2_TYPE_PRESET_PAGE);
  g_type_ensure (ML2_TYPE_PRESETS_PAGE);
  g_type_ensure (ML2_TYPE_VELOCITY_PAGE);

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
ml2_book_on_presets_preset_activated (ScNavigationPage *page, ScActionRow *row)
{
  open_preset_page (page, row, ML2_TYPE_PRESET_PAGE);
}

void
ml2_book_on_presets_ar_presets_activated (ScNavigationPage *page, ScActionRow *row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (AR_TYPE_PRESET_PAGE,
                                          "title", adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row)),
                                          "presets-num", 8,
                                          "readonly-num", 1,
                                          NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
}

void
ml2_book_on_preset_pitch_mod_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, ML2_TYPE_PITCH_MOD_PAGE);
}

void
ml2_book_on_preset_pedal_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, ML2_TYPE_PEDAL_PAGE);
}

void
ml2_book_on_preset_knob_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, ML2_TYPE_KNOB_PAGE);
}

void
ml2_book_on_preset_knob_extra_activated (ScNavigationPage *page, ScActionRow* row)
{
open_preset_page (page, row, ML2_TYPE_KNOB_EXTRA_PAGE);
}

void
ml2_book_on_preset_pad_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, ML2_TYPE_PAD_PAGE);
}
