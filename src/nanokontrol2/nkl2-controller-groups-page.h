#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKL2_TYPE_CONTROLLER_GROUPS_PAGE (nkl2_controller_groups_page_get_type ())

G_DECLARE_FINAL_TYPE (Nkl2ControllerGroupsPage, nkl2_controller_groups_page, NKL2, CONTROLLER_GROUPS_PAGE, ScNavigationPage)

G_END_DECLS
