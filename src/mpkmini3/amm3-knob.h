#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define AMM3_TYPE_KNOB (amm3_knob_get_type ())

G_DECLARE_FINAL_TYPE (Amm3Knob, amm3_knob, AMM3, KNOB, ScPreferencesGroup)

G_END_DECLS
