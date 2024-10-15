#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_MOD_WHEEL_PAGE (ml2_mod_wheel_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2ModWheelPage, ml2_mod_wheel_page, ML2, MOD_WHEEL_PAGE, ScNavigationPage)

G_END_DECLS
