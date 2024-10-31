#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM2_TYPE_PAD_PAGE (amm2_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (Amm2PadPage, amm2_pad_page, AMM2, PAD_PAGE, ScNavigationPage)

G_END_DECLS
