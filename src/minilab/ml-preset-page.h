#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML_TYPE_PRESET_PAGE (ml_preset_page_get_type ())

G_DECLARE_FINAL_TYPE (MlPresetPage, ml_preset_page, ML, PRESET_PAGE, ScNavigationPage)

G_END_DECLS
