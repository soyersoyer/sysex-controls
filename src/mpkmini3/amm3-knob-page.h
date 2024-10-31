#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM3_TYPE_KNOB_PAGE (amm3_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (Amm3KnobPage, amm3_knob_page, AMM3, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
