#pragma once

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define ML3_TYPE_MAIN_KNOB_CLICK (ml3_main_knob_click_get_type ())

G_DECLARE_FINAL_TYPE (Ml3MainKnobClick, ml3_main_knob_click, ML3, MAIN_KNOB_CLICK, ScPreferencesGroup)

G_END_DECLS
