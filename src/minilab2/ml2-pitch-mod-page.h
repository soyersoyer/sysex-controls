#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_PITCH_MOD_PAGE (ml2_pitch_mod_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2PitchModPage, ml2_pitch_mod_page, ML2, PITCH_MOD_PAGE, ScNavigationPage)

G_END_DECLS
