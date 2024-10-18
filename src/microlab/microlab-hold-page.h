#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MICROLAB_TYPE_HOLD_PAGE (microlab_hold_page_get_type ())

G_DECLARE_FINAL_TYPE (MicrolabHoldPage, microlab_hold_page, MICROLAB, HOLD_PAGE, ScNavigationPage)

G_END_DECLS
