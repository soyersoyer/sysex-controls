#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define BSP_TYPE_PAD (bsp_pad_get_type ())

G_DECLARE_FINAL_TYPE (BspPad, bsp_pad, BSP, PAD, ScPreferencesGroup)

G_END_DECLS
