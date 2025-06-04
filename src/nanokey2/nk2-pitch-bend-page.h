#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NK2_TYPE_PITCH_BEND_PAGE (nk2_pitch_bend_page_get_type ())

G_DECLARE_FINAL_TYPE (Nk2PitchBendPage, nk2_pitch_bend_page, NK2, PITCH_BEND_PAGE, ScNavigationPage)

G_END_DECLS
