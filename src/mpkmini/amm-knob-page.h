#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM_TYPE_KNOB_PAGE (amm_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (AmmKnobPage, amm_knob_page, AMM, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
