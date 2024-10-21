#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES3_TYPE_KNOB_PAGE (kles3_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (Kles3KnobPage, kles3_knob_page, KLES3, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
