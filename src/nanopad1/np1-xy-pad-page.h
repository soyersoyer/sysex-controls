#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NP1_TYPE_XY_PAD_PAGE (np1_xy_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (Np1XyPadPage, np1_xy_pad_page, NP1, XY_PAD_PAGE, ScNavigationPage)

G_END_DECLS
