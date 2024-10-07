#pragma once

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define ML3_TYPE_PAD (ml3_pad_get_type ())

G_DECLARE_FINAL_TYPE (Ml3Pad, ml3_pad, ML3, PAD, ScPreferencesGroup)

G_END_DECLS
