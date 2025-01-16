#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL_TYPE_CONTROLLER_PAGE (kl_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (KlControllerPage, kl_controller_page, KL, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
