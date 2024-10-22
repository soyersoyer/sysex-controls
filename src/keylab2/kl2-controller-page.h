#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL2_TYPE_CONTROLLER_PAGE (kl2_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl2ControllerPage, kl2_controller_page, KL2, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
