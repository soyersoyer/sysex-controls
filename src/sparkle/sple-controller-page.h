#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define SPLE_TYPE_CONTROLLER_PAGE (sple_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (SpleControllerPage, sple_controller_page, SPLE, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
