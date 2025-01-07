#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MB2_TYPE_MOD_PITCH_PAGE (mb2_mod_pitch_page_get_type ())

G_DECLARE_FINAL_TYPE (Mb2ModPitchPage, mb2_mod_pitch_page, MB2, MOD_PITCH_PAGE, ScNavigationPage)

G_END_DECLS
