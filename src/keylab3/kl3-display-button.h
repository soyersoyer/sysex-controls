#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KL3_TYPE_DISPLAY_BUTTON (kl3_display_button_get_type ())

G_DECLARE_FINAL_TYPE (Kl3DisplayButton, kl3_display_button, KL3, DISPLAY_BUTTON, ScPreferencesGroup)

G_END_DECLS
