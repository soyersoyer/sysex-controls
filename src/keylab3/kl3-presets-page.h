#pragma once

#include <adwaita.h>

#include "sc-action-row.h"
#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_PRESETS_PAGE (kl3_presets_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3PresetsPage, kl3_presets_page, KL3, PRESETS_PAGE, ScNavigationPage)

void kl3_presets_page_on_preset_activated (Kl3PresetsPage *self, ScActionRow *row);

G_END_DECLS
