#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MB2S_TYPE_MOD_PITCH_PAGE (mb2s_mod_pitch_page_get_type ())

G_DECLARE_FINAL_TYPE (Mb2sModPitchPage, mb2s_mod_pitch_page, MB2S, MOD_PITCH_PAGE, ScNavigationPage)

G_END_DECLS
