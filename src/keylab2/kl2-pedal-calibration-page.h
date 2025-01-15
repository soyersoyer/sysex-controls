#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL2_TYPE_PEDAL_CALIBRATION_PAGE (kl2_pedal_calibration_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl2PedalCalibrationPage, kl2_pedal_calibration_page, KL2, PEDAL_CALIBRATION_PAGE, ScNavigationPage)

G_END_DECLS
