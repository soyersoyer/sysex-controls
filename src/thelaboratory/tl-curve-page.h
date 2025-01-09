#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define TL_TYPE_CURVE_PAGE (tl_curve_page_get_type ())

G_DECLARE_FINAL_TYPE (TlCurvePage, tl_curve_page, TL, CURVE_PAGE, ScNavigationPage)

G_END_DECLS
