#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML_TYPE_PRESETS_PAGE (ml_presets_page_get_type ())

G_DECLARE_FINAL_TYPE (MlPresetsPage, ml_presets_page, ML, PRESETS_PAGE, ScNavigationPage)

G_END_DECLS
