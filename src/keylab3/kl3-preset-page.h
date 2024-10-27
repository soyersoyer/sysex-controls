#pragma once

#include <adwaita.h>

#include "sc-action-row.h"
#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_PRESET_PAGE (kl3_preset_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3PresetPage, kl3_preset_page, KL3, PRESET_PAGE, ScNavigationPage)

void kl3_preset_page_on_keyboard_activated (Kl3PresetPage *self, ScActionRow *row);
void kl3_preset_page_on_pitch_mod_activated (Kl3PresetPage *self, ScActionRow *row);
void kl3_preset_page_on_sea_activated (Kl3PresetPage *self, ScActionRow *row);
void kl3_preset_page_on_main_encoder_activated (Kl3PresetPage *self, ScActionRow *row);
void kl3_preset_page_on_encoder_activated (Kl3PresetPage *self, ScActionRow *row);
void kl3_preset_page_on_fader_activated (Kl3PresetPage *self, ScActionRow *row);
void kl3_preset_page_on_pad_activated (Kl3PresetPage *self, ScActionRow *row);
void kl3_preset_page_on_display_button_activated (Kl3PresetPage *self, ScActionRow *row);

G_END_DECLS
