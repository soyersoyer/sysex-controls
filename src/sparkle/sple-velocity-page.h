#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define SPLE_TYPE_VELOCITY_PAGE (sple_velocity_page_get_type ())

G_DECLARE_FINAL_TYPE (SpleVelocityPage, sple_velocity_page, SPLE, VELOCITY_PAGE, ScNavigationPage)

G_END_DECLS
