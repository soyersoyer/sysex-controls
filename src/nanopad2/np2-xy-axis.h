#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define NP2_TYPE_XY_AXIS (np2_xy_axis_get_type ())

G_DECLARE_FINAL_TYPE (Np2XyAxis, np2_xy_axis, NP2, XY_AXIS, ScPreferencesGroup)

G_END_DECLS
