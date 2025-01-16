#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML_TYPE_VELOCITY_PAGE (ml_velocity_page_get_type ())

G_DECLARE_FINAL_TYPE (MlVelocityPage, ml_velocity_page, ML, VELOCITY_PAGE, ScNavigationPage)

G_END_DECLS
