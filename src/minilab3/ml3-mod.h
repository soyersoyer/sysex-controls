#pragma once

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define ML3_TYPE_MOD (ml3_mod_get_type ())

G_DECLARE_FINAL_TYPE (Ml3Mod, ml3_mod, ML3, MOD, ScPreferencesGroup)

G_END_DECLS
