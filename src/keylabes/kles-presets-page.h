#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES_TYPE_PRESETS_PAGE (kles_presets_page_get_type ())

G_DECLARE_FINAL_TYPE (KlesPresetsPage, kles_presets_page, KLES, PRESETS_PAGE, ScNavigationPage)

G_END_DECLS
