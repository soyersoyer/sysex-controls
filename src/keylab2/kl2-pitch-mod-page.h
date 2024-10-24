#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL2_TYPE_PITCH_MOD_PAGE (kl2_pitch_mod_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl2PitchModPage, kl2_pitch_mod_page, KL2, PITCH_MOD_PAGE, ScNavigationPage)

G_END_DECLS
