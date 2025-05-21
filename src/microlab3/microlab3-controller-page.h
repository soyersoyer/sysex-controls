#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MICROLAB3_TYPE_CONTROLLER_PAGE (microlab3_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (Microlab3ControllerPage, microlab3_controller_page, MICROLAB3, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
