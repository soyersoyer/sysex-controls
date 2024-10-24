#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KL2_TYPE_CV_MOD (kl2_cv_mod_get_type ())

G_DECLARE_FINAL_TYPE (Kl2CvMod, kl2_cv_mod, KL2, CV_MOD, ScPreferencesGroup)

G_END_DECLS
