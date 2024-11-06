#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KLES3_TYPE_BUTTON (kles3_button_get_type ())

G_DECLARE_FINAL_TYPE (Kles3Button, kles3_button, KLES3, BUTTON, ScPreferencesGroup)

G_END_DECLS
