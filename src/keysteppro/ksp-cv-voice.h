#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KSP_TYPE_CV_VOICE (ksp_cv_voice_get_type ())

G_DECLARE_FINAL_TYPE (KspCvVoice, ksp_cv_voice, KSP, CV_VOICE, ScPreferencesGroup)

G_END_DECLS
