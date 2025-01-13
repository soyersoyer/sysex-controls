#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define BSP_TYPE_KNOB (bsp_knob_get_type ())

G_DECLARE_FINAL_TYPE (BspKnob, bsp_knob, BSP, KNOB, ScPreferencesGroup)

G_END_DECLS
