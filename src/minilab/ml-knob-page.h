#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML_TYPE_KNOB_PAGE (ml_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (MlKnobPage, ml_knob_page, ML, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
