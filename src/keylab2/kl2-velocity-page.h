#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL2_TYPE_VELOCITY_PAGE (kl2_velocity_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl2VelocityPage, kl2_velocity_page, KL2, VELOCITY_PAGE, ScNavigationPage)

G_END_DECLS
