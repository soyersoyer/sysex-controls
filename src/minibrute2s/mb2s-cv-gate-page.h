#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MB2S_TYPE_CV_GATE_PAGE (mb2s_cv_gate_page_get_type ())

G_DECLARE_FINAL_TYPE (Mb2sCvGatePage, mb2s_cv_gate_page, MB2S, CV_GATE_PAGE, ScNavigationPage)

G_END_DECLS
