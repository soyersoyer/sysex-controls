#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KL3_TYPE_PEDAL (kl3_pedal_get_type ())

G_DECLARE_FINAL_TYPE (Kl3Pedal, kl3_pedal, KL3, PEDAL, ScPreferencesGroup)

G_END_DECLS
