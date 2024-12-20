#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KSP_TYPE_CV_GATE_PAGE (ksp_cv_gate_page_get_type ())

G_DECLARE_FINAL_TYPE (KspCvGatePage, ksp_cv_gate_page, KSP, CV_GATE_PAGE, ScNavigationPage)

G_END_DECLS
