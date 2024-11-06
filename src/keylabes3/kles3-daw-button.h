#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KLES3_TYPE_DAW_BUTTON (kles3_daw_button_get_type ())

G_DECLARE_FINAL_TYPE (Kles3DawButton, kles3_daw_button, KLES3, DAW_BUTTON, ScPreferencesGroup)

G_END_DECLS
