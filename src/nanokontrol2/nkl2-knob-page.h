#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKL2_TYPE_KNOB_PAGE (nkl2_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (Nkl2KnobPage, nkl2_knob_page, NKL2, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
