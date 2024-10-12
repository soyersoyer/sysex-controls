#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define BS_TYPE_KNOB (bs_knob_get_type ())

G_DECLARE_FINAL_TYPE (BsKnob, bs_knob, BS, KNOB, ScPreferencesGroup)

G_END_DECLS
