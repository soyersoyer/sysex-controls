#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKS_TYPE_TOUCH_PITCH_MOD_PAGE (nks_touch_pitch_mod_page_get_type ())

G_DECLARE_FINAL_TYPE (NksTouchPitchModPage, nks_touch_pitch_mod_page, NKS, TOUCH_PITCH_MOD_PAGE, ScNavigationPage)

G_END_DECLS
