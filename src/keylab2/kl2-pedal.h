#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KL2_TYPE_PEDAL (kl2_pedal_get_type ())

G_DECLARE_FINAL_TYPE (Kl2Pedal, kl2_pedal, KL2, PEDAL, ScPreferencesGroup)

G_END_DECLS
