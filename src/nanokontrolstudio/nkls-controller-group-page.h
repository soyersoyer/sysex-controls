#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKLS_TYPE_CONTROLLER_GROUP_PAGE (nkls_controller_group_page_get_type ())

G_DECLARE_FINAL_TYPE (NklsControllerGroupPage, nkls_controller_group_page, NKLS, CONTROLLER_GROUP_PAGE, ScNavigationPage)

G_END_DECLS
