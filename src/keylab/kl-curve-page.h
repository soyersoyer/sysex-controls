#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL_TYPE_CURVE_PAGE (kl_curve_page_get_type ())

G_DECLARE_FINAL_TYPE (KlCurvePage, kl_curve_page, KL, CURVE_PAGE, ScNavigationPage)

G_END_DECLS
