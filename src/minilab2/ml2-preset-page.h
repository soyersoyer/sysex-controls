#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_PRESET_PAGE (ml2_preset_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2PresetPage, ml2_preset_page, ML2, PRESET_PAGE, ScNavigationPage)

G_END_DECLS
