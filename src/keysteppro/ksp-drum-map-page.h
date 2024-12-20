#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KSP_TYPE_DRUM_MAP_PAGE (ksp_drum_map_page_get_type ())

G_DECLARE_FINAL_TYPE (KspDrumMapPage, ksp_drum_map_page, KSP, DRUM_MAP_PAGE, ScNavigationPage)

G_END_DECLS
