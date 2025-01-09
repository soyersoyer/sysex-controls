#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define TL_TYPE_CONTROLLER_PAGE (tl_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (TlControllerPage, tl_controller_page, TL, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
