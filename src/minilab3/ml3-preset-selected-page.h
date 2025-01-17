#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_PRESET_SELECTED_PAGE (ml3_preset_selected_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3PresetSelectedPage, ml3_preset_selected_page, ML3, PRESET_SELECTED_PAGE, ScNavigationPage)

G_END_DECLS
