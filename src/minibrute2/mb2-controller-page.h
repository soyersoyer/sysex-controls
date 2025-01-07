#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MB2_TYPE_CONTROLLER_PAGE (mb2_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (Mb2ControllerPage, mb2_controller_page, MB2, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
