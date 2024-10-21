#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES3_TYPE_CONTROLLER_PAGE (kles3_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (Kles3ControllerPage, kles3_controller_page, KLES3, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
