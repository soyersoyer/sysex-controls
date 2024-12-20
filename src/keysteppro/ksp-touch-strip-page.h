#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KSP_TYPE_TOUCH_STRIP_PAGE (ksp_touch_strip_page_get_type ())

G_DECLARE_FINAL_TYPE (KspTouchStripPage, ksp_touch_strip_page, KSP, TOUCH_STRIP_PAGE, ScNavigationPage)

G_END_DECLS
