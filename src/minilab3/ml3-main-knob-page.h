#pragma once

#include "sc-preferences-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_MAIN_KNOB_PAGE (ml3_main_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3MainKnobPage, ml3_main_knob_page, ML3, MAIN_KNOB_PAGE, ScPreferencesPage)

G_END_DECLS
