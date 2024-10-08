#pragma once

#include "sc-preferences-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_PRESET_PAGE (ml3_preset_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3PresetPage, ml3_preset_page, ML3, PRESET_PAGE, ScPreferencesPage)

G_END_DECLS
