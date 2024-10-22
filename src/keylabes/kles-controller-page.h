#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES_TYPE_CONTROLLER_PAGE (kles_controller_page_get_type ())

G_DECLARE_FINAL_TYPE (KlesControllerPage, kles_controller_page, KLES, CONTROLLER_PAGE, ScNavigationPage)

G_END_DECLS
