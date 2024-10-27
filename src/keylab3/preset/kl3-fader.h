#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KL3_TYPE_FADER (kl3_fader_get_type ())

G_DECLARE_FINAL_TYPE (Kl3Fader, kl3_fader, KL3, FADER, ScPreferencesGroup)

G_END_DECLS
