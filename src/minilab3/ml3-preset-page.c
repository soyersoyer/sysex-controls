#include "ml3-preset-page.h"

#include "ml3-fader-page.h"
#include "ml3-knob-page.h"
#include "ml3-main-knob-page.h"
#include "ml3-pad-page.h"
#include "ml3-spm-page.h"

struct _Ml3PresetPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3PresetPage, ml3_preset_page, SC_TYPE_NAVIGATION_PAGE)

static uint32_t
get_preset_offset (ScNavigationPage *self)
{
  // 0x08400100 -> 0x04400000
  uint32_t offset = sc_navigation_page_get_control_id_offset (self);
  return 0x03400000 + (offset << 16);
}

void
ml3_preset_page_on_spm_activated (ScNavigationPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (ML3_TYPE_SPM_PAGE, "control-id-offset", get_preset_offset (self), NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
ml3_preset_page_on_main_knob_activated (ScNavigationPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (ML3_TYPE_MAIN_KNOB_PAGE, "control-id-offset", get_preset_offset (self), NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
ml3_preset_page_on_knob_activated (ScNavigationPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (ML3_TYPE_KNOB_PAGE, "control-id-offset", get_preset_offset (self), NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
ml3_preset_page_on_fader_activated (ScNavigationPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (ML3_TYPE_FADER_PAGE, "control-id-offset", get_preset_offset (self), NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
ml3_preset_page_on_pad_a_activated (ScNavigationPage *self, AdwActionRow* row)
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
ml3_preset_page_on_pad_b_activated (ScNavigationPage *self, AdwActionRow* row)
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

static void
ml3_preset_page_class_init (Ml3PresetPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-preset-page.ui");
}

static void
ml3_preset_page_init (Ml3PresetPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
