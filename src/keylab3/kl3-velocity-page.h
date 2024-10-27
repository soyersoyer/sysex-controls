#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_VELOCITY_PAGE (kl3_velocity_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3VelocityPage, kl3_velocity_page, KL3, VELOCITY_PAGE, ScNavigationPage)

G_END_DECLS
