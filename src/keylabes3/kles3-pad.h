#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KLES3_TYPE_PAD (kles3_pad_get_type ())

G_DECLARE_FINAL_TYPE (Kles3Pad, kles3_pad, KLES3, PAD, ScPreferencesGroup)

G_END_DECLS
