#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KS32_TYPE_MOD_PITCH_PAGE (ks32_mod_pitch_page_get_type ())

G_DECLARE_FINAL_TYPE (Ks32ModPitchPage, ks32_mod_pitch_page, KS32, MOD_PITCH_PAGE, ScNavigationPage)

G_END_DECLS
