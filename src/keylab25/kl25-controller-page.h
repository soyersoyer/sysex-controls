#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL25_TYPE_CONTROLLER_PAGE (kl25_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl25ControllerPage, kl25_controller_page, KL25, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
