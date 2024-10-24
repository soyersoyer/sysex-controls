#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KL2_TYPE_KNOB (kl2_knob_get_type ())

G_DECLARE_FINAL_TYPE (Kl2Knob, kl2_knob, KL2, KNOB, ScPreferencesGroup)

G_END_DECLS
