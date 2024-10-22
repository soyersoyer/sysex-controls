#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KLES_TYPE_KNOB (kles_knob_get_type ())

G_DECLARE_FINAL_TYPE (KlesKnob, kles_knob, KLES, KNOB, ScPreferencesGroup)

G_END_DECLS
