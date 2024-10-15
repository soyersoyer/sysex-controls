#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_KNOB_PAGE (ml2_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2KnobPage, ml2_knob_page, ML2, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
