#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM_TYPE_PAD_PAGE (amm_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (AmmPadPage, amm_pad_page, AMM, PAD_PAGE, ScNavigationPage)

G_END_DECLS
