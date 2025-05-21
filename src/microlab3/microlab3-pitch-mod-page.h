#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MICROLAB3_TYPE_PITCH_MOD_PAGE (microlab3_pitch_mod_page_get_type ())

G_DECLARE_FINAL_TYPE (Microlab3PitchModPage, microlab3_pitch_mod_page, MICROLAB3, PITCH_MOD_PAGE, ScNavigationPage)

G_END_DECLS
