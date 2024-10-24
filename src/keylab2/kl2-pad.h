#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KL2_TYPE_PAD (kl2_pad_get_type ())

G_DECLARE_FINAL_TYPE (Kl2Pad, kl2_pad, KL2, PAD, ScPreferencesGroup)

G_END_DECLS
