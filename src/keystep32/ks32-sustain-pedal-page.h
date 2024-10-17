#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KS32_TYPE_SUSTAIN_PEDAL_PAGE (ks32_sustain_pedal_page_get_type ())

G_DECLARE_FINAL_TYPE (Ks32SustainPedalPage, ks32_sustain_pedal_page, KS32, SUSTAIN_PEDAL_PAGE, ScNavigationPage)

G_END_DECLS
