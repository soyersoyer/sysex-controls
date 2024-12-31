#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define DB_TYPE_GLOBAL_PAGE (db_global_page_get_type ())

G_DECLARE_FINAL_TYPE (DbGlobalPage, db_global_page, DB, GLOBAL_PAGE, ScNavigationPage)

G_END_DECLS
