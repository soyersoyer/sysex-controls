#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MB2S_TYPE_CONTROLLER_PAGE (mb2s_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (Mb2sControllerPage, mb2s_controller_page, MB2S, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
