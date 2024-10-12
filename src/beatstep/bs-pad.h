#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define BS_TYPE_PAD (bs_pad_get_type ())

G_DECLARE_FINAL_TYPE (BsPad, bs_pad, BS, PAD, ScPreferencesGroup)

G_END_DECLS
