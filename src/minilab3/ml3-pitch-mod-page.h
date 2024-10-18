#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_PITCH_MOD_PAGE (ml3_pitch_mod_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3PitchModPage, ml3_pitch_mod_page, ML3, PITCH_MOD_PAGE, ScNavigationPage)

G_END_DECLS
