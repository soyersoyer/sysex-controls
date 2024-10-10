#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KS37_TYPE_CV_GATE_PAGE (ks37_cv_gate_page_get_type ())

G_DECLARE_FINAL_TYPE (Ks37CvGatePage, ks37_cv_gate_page, KS37, CV_GATE_PAGE, ScNavigationPage)

G_END_DECLS
