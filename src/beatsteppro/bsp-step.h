#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define BSP_TYPE_STEP (bsp_step_get_type ())

G_DECLARE_FINAL_TYPE (BspStep, bsp_step, BSP, STEP, ScPreferencesGroup)

G_END_DECLS
