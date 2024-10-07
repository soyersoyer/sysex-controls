#pragma once

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define ML3_TYPE_FADER (ml3_fader_get_type ())

G_DECLARE_FINAL_TYPE (Ml3Fader, ml3_fader, ML3, FADER, ScPreferencesGroup)

G_END_DECLS
