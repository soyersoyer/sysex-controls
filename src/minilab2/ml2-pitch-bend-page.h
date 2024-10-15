#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_PITCH_BEND_PAGE (ml2_pitch_bend_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2PitchBendPage, ml2_pitch_bend_page, ML2, PITCH_BEND_PAGE, ScNavigationPage)

G_END_DECLS
