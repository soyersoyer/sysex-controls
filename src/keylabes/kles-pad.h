#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KLES_TYPE_PAD (kles_pad_get_type ())

G_DECLARE_FINAL_TYPE (KlesPad, kles_pad, KLES, PAD, ScPreferencesGroup)

G_END_DECLS
