#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKS_TYPE_TOUCH_XY_PAGE (nks_touch_xy_page_get_type ())

G_DECLARE_FINAL_TYPE (NksTouchXyPage, nks_touch_xy_page, NKS, TOUCH_XY_PAGE, ScNavigationPage)

G_END_DECLS
