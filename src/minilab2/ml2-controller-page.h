#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_CONTROLLER_PAGE (ml2_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2ControllerPage, ml2_controller_page, ML2, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
