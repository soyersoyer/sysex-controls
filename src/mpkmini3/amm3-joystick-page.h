#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM3_TYPE_JOYSTICK_PAGE (amm3_joystick_page_get_type ())

G_DECLARE_FINAL_TYPE (Amm3JoystickPage, amm3_joystick_page, AMM3, JOYSTICK_PAGE, ScNavigationPage)

G_END_DECLS
