#pragma once

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_PRESET_PAGE (ml3_preset_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3PresetPage, ml3_preset_page, ML3, PRESET_PAGE, ScNavigationPage)

void ml3_preset_page_on_spm_activated (ScNavigationPage *self, AdwActionRow* row);
void ml3_preset_page_on_main_knob_activated (ScNavigationPage *self, AdwActionRow* row);
void ml3_preset_page_on_knob_activated (ScNavigationPage *self, AdwActionRow* row);
void ml3_preset_page_on_fader_activated (ScNavigationPage *self, AdwActionRow* row);
void ml3_preset_page_on_pad_a_activated (ScNavigationPage *self, AdwActionRow* row);
void ml3_preset_page_on_pad_b_activated (ScNavigationPage *self, AdwActionRow* row);

G_END_DECLS
