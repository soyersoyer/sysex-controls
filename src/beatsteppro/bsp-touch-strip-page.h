#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_TOUCH_STRIP_PAGE (bsp_touch_strip_page_get_type ())

G_DECLARE_FINAL_TYPE (BspTouchStripPage, bsp_touch_strip_page, BSP, TOUCH_STRIP_PAGE, ScNavigationPage)

G_END_DECLS
