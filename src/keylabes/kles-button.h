#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KLES_TYPE_BUTTON (kles_button_get_type ())

G_DECLARE_FINAL_TYPE (KlesButton, kles_button, KLES, BUTTON, ScPreferencesGroup)

G_END_DECLS
