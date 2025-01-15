#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES_TYPE_PRESET_PAGE (kles_preset_page_get_type ())

G_DECLARE_FINAL_TYPE (KlesPresetPage, kles_preset_page, KLES, PRESET_PAGE, ScNavigationPage)

G_END_DECLS
