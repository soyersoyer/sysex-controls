#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define ML2_TYPE_BUTTON (ml2_button_get_type ())

G_DECLARE_FINAL_TYPE (Ml2Button, ml2_button, ML2, BUTTON, ScPreferencesGroup)

G_END_DECLS
