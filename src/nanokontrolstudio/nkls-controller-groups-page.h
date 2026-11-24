#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKLS_TYPE_CONTROLLER_GROUPS_PAGE (nkls_controller_groups_page_get_type ())

G_DECLARE_FINAL_TYPE (NklsControllerGroupsPage, nkls_controller_groups_page, NKLS, CONTROLLER_GROUPS_PAGE, ScNavigationPage)

G_END_DECLS
