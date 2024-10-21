#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES3_TYPE_MAIN_KNOB_PAGE (kles3_main_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (Kles3MainKnobPage, kles3_main_knob_page, KLES3, MAIN_KNOB_PAGE, ScNavigationPage)

G_END_DECLS
