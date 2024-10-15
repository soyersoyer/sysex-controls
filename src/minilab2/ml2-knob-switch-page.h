#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_KNOB_SWITCH_PAGE (ml2_knob_switch_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2KnobSwitchPage, ml2_knob_switch_page, ML2, KNOB_SWITCH_PAGE, ScNavigationPage)

G_END_DECLS
