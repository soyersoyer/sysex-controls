#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KS32_TYPE_CV_GATE_PAGE (ks32_cv_gate_page_get_type ())

G_DECLARE_FINAL_TYPE (Ks32CvGatePage, ks32_cv_gate_page, KS32, CV_GATE_PAGE, ScNavigationPage)

G_END_DECLS
