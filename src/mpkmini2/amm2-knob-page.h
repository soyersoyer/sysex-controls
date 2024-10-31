#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM2_TYPE_KNOB_PAGE (amm2_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (Amm2KnobPage, amm2_knob_page, AMM2, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
