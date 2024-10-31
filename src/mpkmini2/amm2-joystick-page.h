#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM2_TYPE_JOYSTICK_PAGE (amm2_joystick_page_get_type ())

G_DECLARE_FINAL_TYPE (Amm2JoystickPage, amm2_joystick_page, AMM2, JOYSTICK_PAGE, ScNavigationPage)

G_END_DECLS
