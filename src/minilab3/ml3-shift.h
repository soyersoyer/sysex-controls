#pragma once

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define ML3_TYPE_SHIFT (ml3_shift_get_type ())

G_DECLARE_FINAL_TYPE (Ml3Shift, ml3_shift, ML3, SHIFT, ScPreferencesGroup)

G_END_DECLS
