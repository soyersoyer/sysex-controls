#pragma once

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define ML3_TYPE_KNOB (ml3_knob_get_type ())

G_DECLARE_FINAL_TYPE (Ml3Knob, ml3_knob, ML3, KNOB, ScPreferencesGroup)

G_END_DECLS
