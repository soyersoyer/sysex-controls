#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_PRESETS_PAGE (ml3_presets_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3PresetsPage, ml3_presets_page, ML3, PRESETS_PAGE, ScNavigationPage)

G_END_DECLS
