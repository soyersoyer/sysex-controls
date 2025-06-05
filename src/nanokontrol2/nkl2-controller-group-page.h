#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKL2_TYPE_CONTROLLER_GROUP_PAGE (nkl2_controller_group_page_get_type ())

G_DECLARE_FINAL_TYPE (Nkl2ControllerGroupPage, nkl2_controller_group_page, NKL2, CONTROLLER_GROUP_PAGE, ScNavigationPage)

G_END_DECLS
