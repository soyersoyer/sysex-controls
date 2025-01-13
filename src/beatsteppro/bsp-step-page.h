#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_STEP_PAGE (bsp_step_page_get_type ())

G_DECLARE_FINAL_TYPE (BspStepPage, bsp_step_page, BSP, STEP_PAGE, ScNavigationPage)

G_END_DECLS
