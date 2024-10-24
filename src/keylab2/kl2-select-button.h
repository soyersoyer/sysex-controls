#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KL2_TYPE_SELECT_BUTTON (kl2_select_button_get_type ())

G_DECLARE_FINAL_TYPE (Kl2SelectButton, kl2_select_button, KL2, SELECT_BUTTON, ScPreferencesGroup)

G_END_DECLS
