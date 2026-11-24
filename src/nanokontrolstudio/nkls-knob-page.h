#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKLS_TYPE_KNOB_PAGE (nkls_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (NklsKnobPage, nkls_knob_page, NKLS, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
