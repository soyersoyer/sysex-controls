#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_METRONOME_PAGE (bsp_metronome_page_get_type ())

G_DECLARE_FINAL_TYPE (BspMetronomePage, bsp_metronome_page, BSP, METRONOME_PAGE, ScNavigationPage)

G_END_DECLS
