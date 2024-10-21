#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES3_TYPE_PITCH_MOD_PAGE (kles3_pitch_mod_page_get_type ())

G_DECLARE_FINAL_TYPE (Kles3PitchModPage, kles3_pitch_mod_page, KLES3, PITCH_MOD_PAGE, ScNavigationPage)

G_END_DECLS
