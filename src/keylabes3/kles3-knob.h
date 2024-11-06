#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KLES3_TYPE_KNOB (kles3_knob_get_type ())

G_DECLARE_FINAL_TYPE (Kles3Knob, kles3_knob, KLES3, KNOB, ScPreferencesGroup)

G_END_DECLS
