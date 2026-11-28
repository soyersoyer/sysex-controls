#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKLS_TYPE_JOG_WHEEL_PAGE (nkls_jog_wheel_page_get_type ())

G_DECLARE_FINAL_TYPE (NklsJogWheelPage, nkls_jog_wheel_page, NKLS, JOG_WHEEL_PAGE, ScNavigationPage)

G_END_DECLS
