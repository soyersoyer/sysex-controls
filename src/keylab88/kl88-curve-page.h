#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL88_TYPE_CURVE_PAGE (kl88_curve_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl88CurvePage, kl88_curve_page, KL88, CURVE_PAGE, ScNavigationPage)

G_END_DECLS
