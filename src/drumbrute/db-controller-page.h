#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define DB_TYPE_CONTROLLER_PAGE (db_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (DbControllerPage, db_controller_page, DB, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
