#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MB2_TYPE_CV_GATE_PAGE (mb2_cv_gate_page_get_type ())

G_DECLARE_FINAL_TYPE (Mb2CvGatePage, mb2_cv_gate_page, MB2, CV_GATE_PAGE, ScNavigationPage)

G_END_DECLS
