#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_USER_SCALE_PAGE (bsp_user_scale_page_get_type ())

G_DECLARE_FINAL_TYPE (BspUserScalePage, bsp_user_scale_page, BSP, USER_SCALE_PAGE, ScNavigationPage)

G_END_DECLS
