#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define BSP_TYPE_DRUM_GROUP (bsp_drum_group_get_type ())

G_DECLARE_FINAL_TYPE (BspDrumGroup, bsp_drum_group, BSP, DRUM_GROUP, ScPreferencesGroup)

G_END_DECLS
