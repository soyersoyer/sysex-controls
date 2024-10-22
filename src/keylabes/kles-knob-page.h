#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES_TYPE_KNOB_PAGE (kles_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (KlesKnobPage, kles_knob_page, KLES, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
