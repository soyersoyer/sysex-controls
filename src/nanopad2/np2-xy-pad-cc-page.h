#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NP2_TYPE_XY_PAD_CC_PAGE (np2_xy_pad_cc_page_get_type ())

G_DECLARE_FINAL_TYPE (Np2XyPadCcPage, np2_xy_pad_cc_page, NP2, XY_PAD_CC_PAGE, ScNavigationPage)

G_END_DECLS
