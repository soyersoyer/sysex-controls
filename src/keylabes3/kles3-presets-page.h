#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES3_TYPE_PRESETS_PAGE (kles3_presets_page_get_type ())

G_DECLARE_FINAL_TYPE (Kles3PresetsPage, kles3_presets_page, KLES3, PRESETS_PAGE, ScNavigationPage)

G_END_DECLS
