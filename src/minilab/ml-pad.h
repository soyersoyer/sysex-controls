#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define ML_TYPE_PAD (ml_pad_get_type ())

G_DECLARE_FINAL_TYPE (MlPad, ml_pad, ML, PAD, ScPreferencesGroup)

G_END_DECLS
