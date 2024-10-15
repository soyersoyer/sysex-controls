#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define ML2_TYPE_KNOB (ml2_knob_get_type ())

G_DECLARE_FINAL_TYPE (Ml2Knob, ml2_knob, ML2, KNOB, ScPreferencesGroup)

G_END_DECLS
