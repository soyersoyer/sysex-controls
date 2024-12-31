#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define DB_TYPE_ROLLER_PAGE (db_roller_page_get_type ())

G_DECLARE_FINAL_TYPE (DbRollerPage, db_roller_page, DB, ROLLER_PAGE, ScNavigationPage)

G_END_DECLS
