#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKS_TYPE_TOUCH_SCALE_PAGE (nks_touch_scale_page_get_type ())

G_DECLARE_FINAL_TYPE (NksTouchScalePage, nks_touch_scale_page, NKS, TOUCH_SCALE_PAGE, ScNavigationPage)

G_END_DECLS
