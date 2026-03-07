#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKL1_TYPE_KNOB_PAGE (nkl1_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (Nkl1KnobPage, nkl1_knob_page, NKL1, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
