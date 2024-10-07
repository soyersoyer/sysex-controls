#pragma once

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define ML3_TYPE_PITCH (ml3_pitch_get_type ())

G_DECLARE_FINAL_TYPE (Ml3Pitch, ml3_pitch, ML3, PITCH, ScPreferencesGroup)

G_END_DECLS
