#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES3_TYPE_PRESET_PAGE (kles3_preset_page_get_type ())

G_DECLARE_FINAL_TYPE (Kles3PresetPage, kles3_preset_page, KLES3, PRESET_PAGE, ScNavigationPage)

G_END_DECLS
