#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KSP_TYPE_CONTROLLER_PAGE (ksp_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (KspControllerPage, ksp_controller_page, KSP, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
