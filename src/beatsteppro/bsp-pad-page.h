#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_PAD_PAGE (bsp_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (BspPadPage, bsp_pad_page, BSP, PAD_PAGE, ScNavigationPage)

G_END_DECLS
