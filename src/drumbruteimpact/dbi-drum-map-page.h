#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define DBI_TYPE_DRUM_MAP_PAGE (dbi_drum_map_page_get_type ())

G_DECLARE_FINAL_TYPE (DbiDrumMapPage, dbi_drum_map_page, DBI, DRUM_MAP_PAGE, ScNavigationPage)

G_END_DECLS
