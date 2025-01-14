#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_DRUM_PAGE (bsp_drum_page_get_type ())

G_DECLARE_FINAL_TYPE (BspDrumPage, bsp_drum_page, BSP, DRUM_PAGE, ScNavigationPage)

G_END_DECLS
