#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL2_TYPE_PRESETS_PAGE (kl2_presets_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl2PresetsPage, kl2_presets_page, KL2, PRESETS_PAGE, ScNavigationPage)

G_END_DECLS
