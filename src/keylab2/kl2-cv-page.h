#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL2_TYPE_CV_PAGE (kl2_cv_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl2CvPage, kl2_cv_page, KL2, CV_PAGE, ScNavigationPage)

G_END_DECLS
