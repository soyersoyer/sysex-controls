#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KL3_TYPE_PAD (kl3_pad_get_type ())

G_DECLARE_FINAL_TYPE (Kl3Pad, kl3_pad, KL3, PAD, ScPreferencesGroup)

G_END_DECLS
