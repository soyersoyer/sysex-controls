#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KL3_TYPE_ENCODER (kl3_encoder_get_type ())

G_DECLARE_FINAL_TYPE (Kl3Encoder, kl3_encoder, KL3, ENCODER, ScPreferencesGroup)

G_END_DECLS
