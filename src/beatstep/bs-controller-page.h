#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BS_TYPE_CONTROLLER_PAGE (bs_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (BsControllerPage, bs_controller_page, BS, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
