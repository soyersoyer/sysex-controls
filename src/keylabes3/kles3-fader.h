#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KLES3_TYPE_FADER (kles3_fader_get_type ())

G_DECLARE_FINAL_TYPE (Kles3Fader, kles3_fader, KLES3, FADER, ScPreferencesGroup)

G_END_DECLS
