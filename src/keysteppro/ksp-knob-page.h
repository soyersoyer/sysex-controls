#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KSP_TYPE_KNOB_PAGE (ksp_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (KspKnobPage, ksp_knob_page, KSP, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
