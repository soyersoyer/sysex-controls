#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define AMM_TYPE_KNOB (amm_knob_get_type ())

G_DECLARE_FINAL_TYPE (AmmKnob, amm_knob, AMM, KNOB, ScPreferencesGroup)

G_END_DECLS
