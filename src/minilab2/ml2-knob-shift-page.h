#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_KNOB_SHIFT_PAGE (ml2_knob_shift_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2KnobShiftPage, ml2_knob_shift_page, ML2, KNOB_SHIFT_PAGE, ScNavigationPage)

G_END_DECLS
