#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_PRESET_PAGE (kl3_preset_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3PresetPage, kl3_preset_page, KL3, PRESET_PAGE, ScNavigationPage)

G_END_DECLS
