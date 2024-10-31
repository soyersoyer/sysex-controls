#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM3_TYPE_PAD_PAGE (amm3_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (Amm3PadPage, amm3_pad_page, AMM3, PAD_PAGE, ScNavigationPage)

G_END_DECLS
