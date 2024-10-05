#pragma once

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define ML2_TYPE_PAD (ml2_pad_get_type ())

G_DECLARE_FINAL_TYPE (Ml2Pad, ml2_pad, ML2, PAD, ScPreferencesGroup)

G_END_DECLS
