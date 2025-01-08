#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_CV_GATE_PAGE (bsp_cv_gate_page_get_type ())

G_DECLARE_FINAL_TYPE (BspCvGatePage, bsp_cv_gate_page, BSP, CV_GATE_PAGE, ScNavigationPage)

G_END_DECLS
