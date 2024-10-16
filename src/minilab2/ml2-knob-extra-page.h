#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_KNOB_EXTRA_PAGE (ml2_knob_extra_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2KnobExtraPage, ml2_knob_extra_page, ML2, KNOB_EXTRA_PAGE, ScNavigationPage)

G_END_DECLS
