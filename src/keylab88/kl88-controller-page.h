#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL88_TYPE_CONTROLLER_PAGE (kl88_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl88ControllerPage, kl88_controller_page, KL88, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
