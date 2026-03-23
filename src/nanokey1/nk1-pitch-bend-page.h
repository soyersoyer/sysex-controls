#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NK1_TYPE_PITCH_BEND_PAGE (nk1_pitch_bend_page_get_type ())

G_DECLARE_FINAL_TYPE (Nk1PitchBendPage, nk1_pitch_bend_page, NK1, PITCH_BEND_PAGE, ScNavigationPage)

G_END_DECLS
