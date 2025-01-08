#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_DRUM_MAP_PAGE (bsp_drum_map_page_get_type ())

G_DECLARE_FINAL_TYPE (BspDrumMapPage, bsp_drum_map_page, BSP, DRUM_MAP_PAGE, ScNavigationPage)

G_END_DECLS
