#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define AMM2_TYPE_KNOB (amm2_knob_get_type ())

G_DECLARE_FINAL_TYPE (Amm2Knob, amm2_knob, AMM2, KNOB, ScPreferencesGroup)

G_END_DECLS
