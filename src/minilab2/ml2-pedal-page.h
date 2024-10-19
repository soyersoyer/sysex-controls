#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_PEDAL_PAGE (ml2_pedal_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2PedalPage, ml2_pedal_page, ML2, PEDAL_PAGE, ScNavigationPage)

G_END_DECLS
