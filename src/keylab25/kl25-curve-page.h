#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL25_TYPE_CURVE_PAGE (kl25_curve_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl25CurvePage, kl25_curve_page, KL25, CURVE_PAGE, ScNavigationPage)

G_END_DECLS
