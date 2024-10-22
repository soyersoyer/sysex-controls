#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES_TYPE_VELOCITY_PAGE (kles_velocity_page_get_type ())

G_DECLARE_FINAL_TYPE (KlesVelocityPage, kles_velocity_page, KLES, VELOCITY_PAGE, ScNavigationPage)

G_END_DECLS
