#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML_TYPE_PITCH_MOD_PAGE (ml_pitch_mod_page_get_type ())

G_DECLARE_FINAL_TYPE (MlPitchModPage, ml_pitch_mod_page, ML, PITCH_MOD_PAGE, ScNavigationPage)

G_END_DECLS
