#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_PRESETS_PAGE (ml2_presets_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2PresetsPage, ml2_presets_page, ML2, PRESETS_PAGE, ScNavigationPage)

G_END_DECLS
