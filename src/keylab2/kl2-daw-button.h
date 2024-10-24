#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KL2_TYPE_DAW_BUTTON (kl2_daw_button_get_type ())

G_DECLARE_FINAL_TYPE (Kl2DawButton, kl2_daw_button, KL2, DAW_BUTTON, ScPreferencesGroup)

G_END_DECLS
