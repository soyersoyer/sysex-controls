#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_CONTROLLER_PAGE (kl3_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3ControllerPage, kl3_controller_page, KL3, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
