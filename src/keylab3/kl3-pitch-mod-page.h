#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_PITCH_MOD_PAGE (kl3_pitch_mod_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3PitchModPage, kl3_pitch_mod_page, KL3, PITCH_MOD_PAGE, ScNavigationPage)

G_END_DECLS
