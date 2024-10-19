#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_VELOCITY_PAGE (ml2_velocity_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2VelocityPage, ml2_velocity_page, ML2, VELOCITY_PAGE, ScNavigationPage)

G_END_DECLS
