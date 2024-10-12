#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BS_TYPE_KNOB_PAGE (bs_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (BsKnobPage, bs_knob_page, BS, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
