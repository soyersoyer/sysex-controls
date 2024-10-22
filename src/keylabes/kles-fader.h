#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KLES_TYPE_FADER (kles_fader_get_type ())

G_DECLARE_FINAL_TYPE (KlesFader, kles_fader, KLES, FADER, ScPreferencesGroup)

G_END_DECLS
