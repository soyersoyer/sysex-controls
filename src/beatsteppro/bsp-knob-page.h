#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_KNOB_PAGE (bsp_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (BspKnobPage, bsp_knob_page, BSP, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
