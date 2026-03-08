#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define NP1_TYPE_XY_AXIS (np1_xy_axis_get_type ())

G_DECLARE_FINAL_TYPE (Np1XyAxis, np1_xy_axis, NP1, XY_AXIS, ScPreferencesGroup)

G_END_DECLS
