#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_CONTROLLER_PAGE (ml3_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3ControllerPage, ml3_controller_page, ML3, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
