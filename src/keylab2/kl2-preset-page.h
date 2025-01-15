#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL2_TYPE_PRESET_PAGE (kl2_preset_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl2PresetPage, kl2_preset_page, KL2, PRESET_PAGE, ScNavigationPage)

G_END_DECLS
