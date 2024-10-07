#pragma once

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define ML3_TYPE_MAIN_KNOB (ml3_main_knob_get_type ())

G_DECLARE_FINAL_TYPE (Ml3MainKnob, ml3_main_knob, ML3, MainKnob, ScPreferencesGroup)

G_END_DECLS
