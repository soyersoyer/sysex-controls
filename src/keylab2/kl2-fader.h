#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KL2_TYPE_FADER (kl2_fader_get_type ())

G_DECLARE_FINAL_TYPE (Kl2Fader, kl2_fader, KL2, FADER, ScPreferencesGroup)

G_END_DECLS
