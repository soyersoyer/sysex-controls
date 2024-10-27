#include "kl3-preset-page.h"

#include "preset/kl3-display-button.h"
#include "preset/kl3-display-button-page.h"
#include "preset/kl3-encoder.h"
#include "preset/kl3-encoder-page.h"
#include "preset/kl3-fader.h"
#include "preset/kl3-fader-page.h"
#include "preset/kl3-keyboard-page.h"
#include "preset/kl3-main-encoder-page.h"
#include "preset/kl3-pad.h"
#include "preset/kl3-pad-bank-page.h"
#include "preset/kl3-pad-page.h"
#include "preset/kl3-pedal.h"
#include "preset/kl3-pitch-mod-page.h"
#include "preset/kl3-sea-page.h"

struct _Kl3PresetPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3PresetPage, kl3_preset_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_preset_page_class_init (Kl3PresetPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-preset-page.ui");
}

static void
kl3_preset_page_init (Kl3PresetPage *self)
{
  g_type_ensure (KL3_TYPE_DISPLAY_BUTTON);
  g_type_ensure (KL3_TYPE_DISPLAY_BUTTON_PAGE);
  g_type_ensure (KL3_TYPE_ENCODER);
  g_type_ensure (KL3_TYPE_ENCODER_PAGE);
  g_type_ensure (KL3_TYPE_FADER);
  g_type_ensure (KL3_TYPE_FADER_PAGE);
  g_type_ensure (KL3_TYPE_KEYBOARD_PAGE);
  g_type_ensure (KL3_TYPE_MAIN_ENCODER_PAGE);
  g_type_ensure (KL3_TYPE_PAD);
  g_type_ensure (KL3_TYPE_PAD_BANK_PAGE);
  g_type_ensure (KL3_TYPE_PAD_PAGE);
  g_type_ensure (KL3_TYPE_PEDAL);
  g_type_ensure (KL3_TYPE_PITCH_MOD_PAGE);
  g_type_ensure (KL3_TYPE_SEA_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

static void
open_page (Kl3PresetPage *self, ScActionRow *row, GType type)
{
  uint32_t control_id_offset = sc_navigation_page_get_control_id_offset (SC_NAVIGATION_PAGE (self)) + sc_action_row_get_control_id_offset (row);
  uint32_t control_cc_offset = sc_navigation_page_get_control_cc_offset (SC_NAVIGATION_PAGE (self)) + sc_action_row_get_control_cc_offset (row);
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (type,
                                          "title", adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row)),
                                          "control-id-offset", control_id_offset,
                                          "control-cc-offset", control_cc_offset,
                                          NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}

void
kl3_preset_page_on_keyboard_activated (Kl3PresetPage *self, ScActionRow *row)
{
  open_page(self, row, KL3_TYPE_KEYBOARD_PAGE);
}

void
kl3_preset_page_on_pitch_mod_activated (Kl3PresetPage *self, ScActionRow *row)
{
  open_page(self, row, KL3_TYPE_PITCH_MOD_PAGE);
}

void
kl3_preset_page_on_sea_activated (Kl3PresetPage *self, ScActionRow *row)
{
  open_page(self, row, KL3_TYPE_SEA_PAGE);
}

void
kl3_preset_page_on_main_encoder_activated (Kl3PresetPage *self, ScActionRow *row)
{
  open_page(self, row, KL3_TYPE_MAIN_ENCODER_PAGE);
}

void
kl3_preset_page_on_encoder_activated (Kl3PresetPage *self, ScActionRow *row)
{
  open_page(self, row, KL3_TYPE_ENCODER_PAGE);
}

void
kl3_preset_page_on_fader_activated (Kl3PresetPage *self, ScActionRow *row)
{
  open_page(self, row, KL3_TYPE_FADER_PAGE);
}

void
kl3_preset_page_on_pad_activated (Kl3PresetPage *self, ScActionRow *row)
{
  open_page(self, row, KL3_TYPE_PAD_PAGE);
}

void
kl3_preset_page_on_display_button_activated (Kl3PresetPage *self, ScActionRow *row)
{
  open_page(self, row, KL3_TYPE_DISPLAY_BUTTON_PAGE);
}
