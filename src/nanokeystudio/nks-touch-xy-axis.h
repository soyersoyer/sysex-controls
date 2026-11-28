#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define NKS_TYPE_TOUCH_XY_AXIS (nks_touch_xy_axis_get_type ())

G_DECLARE_FINAL_TYPE (NksTouchXyAxis, nks_touch_xy_axis, NKS, TOUCH_XY_AXIS, ScPreferencesGroup)

G_END_DECLS
