#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_CONTROLLER_PAGE (bsp_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (BspControllerPage, bsp_controller_page, BSP, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
