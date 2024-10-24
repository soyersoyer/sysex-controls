#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KL2_TYPE_PEDAL_CALIBRATION (kl2_pedal_calibration_get_type ())

G_DECLARE_FINAL_TYPE (Kl2PedalCalibration, kl2_pedal_calibration, KL2, PEDAL_CALIBRATION, ScPreferencesGroup)

G_END_DECLS
