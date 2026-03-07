#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKL1_TYPE_CONTROLLER_GROUPS_PAGE (nkl1_controller_groups_page_get_type ())

G_DECLARE_FINAL_TYPE (Nkl1ControllerGroupsPage, nkl1_controller_groups_page, NKL1, CONTROLLER_GROUPS_PAGE, ScNavigationPage)

G_END_DECLS
