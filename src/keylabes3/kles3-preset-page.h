#pragma once

#include <adwaita.h>

#include "sc-action-row.h"
#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES3_TYPE_PRESET_PAGE (kles3_preset_page_get_type ())

G_DECLARE_FINAL_TYPE (Kles3PresetPage, kles3_preset_page, KLES3, PRESET_PAGE, ScNavigationPage)

void kles3_preset_page_on_pitch_mod_activated (ScNavigationPage *self, ScActionRow* row);
void kles3_preset_page_on_main_knob_activated (ScNavigationPage *self, ScActionRow* row);
void kles3_preset_page_on_knob_activated (ScNavigationPage *self, ScActionRow* row);
void kles3_preset_page_on_button_activated (ScNavigationPage *self, ScActionRow* row);
void kles3_preset_page_on_fader_activated (ScNavigationPage *self, ScActionRow* row);
void kles3_preset_page_on_pad_a_activated (ScNavigationPage *self, ScActionRow* row);
void kles3_preset_page_on_pad_b_activated (ScNavigationPage *self, ScActionRow* row);

G_END_DECLS
