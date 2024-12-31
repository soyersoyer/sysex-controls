#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define DB_TYPE_DRUM_MAP_PAGE (db_drum_map_page_get_type ())

G_DECLARE_FINAL_TYPE (DbDrumMapPage, db_drum_map_page, DB, DRUM_MAP_PAGE, ScNavigationPage)

G_END_DECLS
