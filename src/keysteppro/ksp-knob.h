#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KSP_TYPE_KNOB (ksp_knob_get_type ())

G_DECLARE_FINAL_TYPE (KspKnob, ksp_knob, KSP, KNOB, ScPreferencesGroup)

G_END_DECLS
