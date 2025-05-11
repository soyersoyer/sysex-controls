#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define AMM_TYPE_PAD (amm_pad_get_type ())

G_DECLARE_FINAL_TYPE (AmmPad, amm_pad, AMM, PAD, ScPreferencesGroup)

G_END_DECLS
