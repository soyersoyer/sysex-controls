#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML_TYPE_CONTROLLER_PAGE (ml_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (MlControllerPage, ml_controller_page, ML, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
