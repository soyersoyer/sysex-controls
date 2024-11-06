#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KLES3_TYPE_LED_COLOR (kles3_led_color_get_type ())

G_DECLARE_FINAL_TYPE (Kles3LedColor, kles3_led_color, KLES3, LED_COLOR, ScPreferencesGroup)

G_END_DECLS
