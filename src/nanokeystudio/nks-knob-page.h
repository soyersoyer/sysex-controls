#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKS_TYPE_KNOB_PAGE (nks_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (NksKnobPage, nks_knob_page, NKS, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
