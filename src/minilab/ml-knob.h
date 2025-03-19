#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define ML_TYPE_KNOB (ml_knob_get_type ())

G_DECLARE_FINAL_TYPE (MlKnob, ml_knob, ML, KNOB, ScPreferencesGroup)

G_END_DECLS
