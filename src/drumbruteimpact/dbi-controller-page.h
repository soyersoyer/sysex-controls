#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define DBI_TYPE_CONTROLLER_PAGE (dbi_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (DbiControllerPage, dbi_controller_page, DBI, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
