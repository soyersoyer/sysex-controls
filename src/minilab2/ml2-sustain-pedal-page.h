#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_SUSTAIN_PEDAL_PAGE (ml2_sustain_pedal_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2SustainPedalPage, ml2_sustain_pedal_page, ML2, SUSTAIN_PEDAL_PAGE, ScNavigationPage)

G_END_DECLS
