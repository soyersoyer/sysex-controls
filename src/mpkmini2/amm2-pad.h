#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define AMM2_TYPE_PAD (amm2_pad_get_type ())

G_DECLARE_FINAL_TYPE (Amm2Pad, amm2_pad, AMM2, PAD, ScPreferencesGroup)

G_END_DECLS
