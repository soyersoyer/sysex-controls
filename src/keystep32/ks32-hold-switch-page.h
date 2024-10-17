#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KS32_TYPE_HOLD_SWITCH_PAGE (ks32_hold_switch_page_get_type ())

G_DECLARE_FINAL_TYPE (Ks32HoldSwitchPage, ks32_hold_switch_page, KS32, HOLD_SWITCH_PAGE, ScNavigationPage)

G_END_DECLS
