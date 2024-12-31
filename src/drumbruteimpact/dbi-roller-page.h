#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define DBI_TYPE_ROLLER_PAGE (dbi_roller_page_get_type ())

G_DECLARE_FINAL_TYPE (DbiRollerPage, dbi_roller_page, DBI, ROLLER_PAGE, ScNavigationPage)

G_END_DECLS
