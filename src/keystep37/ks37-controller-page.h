#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KS37_TYPE_CONTROLLER_PAGE (ks37_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (Ks37ControllerPage, ks37_controller_page, KS37, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
