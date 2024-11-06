#include "kles3-preset-page.h"

#include "kles3-button.h"
#include "kles3-button-page.h"
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
#include "kles3-pitch-mod-page.h"

struct _Kles3PresetPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3PresetPage, kles3_preset_page, SC_TYPE_NAVIGATION_PAGE)

static uint32_t
get_preset_offset (ScNavigationPage *self)
{
  // 0x09400100 -> 0x04400000
  uint32_t offset = sc_navigation_page_get_control_id_offset (self);
  return 0x03400000 + (offset << 16);
}

void
kles3_preset_page_on_pitch_mod_activated (ScNavigationPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (KLES3_TYPE_PITCH_MOD_PAGE, "control-id-offset", get_preset_offset (self), NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
kles3_preset_page_on_main_knob_activated (ScNavigationPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (KLES3_TYPE_MAIN_KNOB_PAGE, "control-id-offset", get_preset_offset (self), NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
kles3_preset_page_on_knob_activated (ScNavigationPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (KLES3_TYPE_KNOB_PAGE, "control-id-offset", get_preset_offset (self), NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
kles3_preset_page_on_button_activated (ScNavigationPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (KLES3_TYPE_BUTTON_PAGE, "control-id-offset", get_preset_offset (self), NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
kles3_preset_page_on_fader_activated (ScNavigationPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (KLES3_TYPE_FADER_PAGE, "control-id-offset", get_preset_offset (self), NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
kles3_preset_page_on_pad_a_activated (ScNavigationPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (KLES3_TYPE_PAD_PAGE,
                                          "control-id-offset", get_preset_offset (self),
                                          "control-cc-offset", get_preset_offset (self),
                                          "title", "Pads Bank A",
                                          NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
kles3_preset_page_on_pad_b_activated (ScNavigationPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (KLES3_TYPE_PAD_PAGE,
                                          "control-id-offset", get_preset_offset (self) + 0x0800,
                                          "control-cc-offset", get_preset_offset (self) + 0x0100,
                                          "title", "Pads Bank B",
                                          NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}


static void
kles3_preset_page_class_init (Kles3PresetPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-preset-page.ui");
}

static void
kles3_preset_page_init (Kles3PresetPage *self)
{
  g_type_ensure (KLES3_TYPE_BUTTON);
  g_type_ensure (KLES3_TYPE_BUTTON_PAGE);
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
  g_type_ensure (KLES3_TYPE_PITCH_MOD_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
