#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NP2_TYPE_XY_PAD_TS_PAGE (np2_xy_pad_ts_page_get_type ())

G_DECLARE_FINAL_TYPE (Np2XyPadTsPage, np2_xy_pad_ts_page, NP2, XY_PAD_TS_PAGE, ScNavigationPage)

G_END_DECLS
