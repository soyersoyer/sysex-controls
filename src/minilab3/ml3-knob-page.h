#pragma once

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_KNOB_PAGE (ml3_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3KnobPage, ml3_knob_page, ML3, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
