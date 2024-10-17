#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KS32_TYPE_CONTROLLER_PAGE (ks32_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (Ks32ControllerPage, ks32_controller_page, KS32, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
