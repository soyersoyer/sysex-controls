#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define AMM3_TYPE_PAD (amm3_pad_get_type ())

G_DECLARE_FINAL_TYPE (Amm3Pad, amm3_pad, AMM3, PAD, ScPreferencesGroup)

G_END_DECLS
