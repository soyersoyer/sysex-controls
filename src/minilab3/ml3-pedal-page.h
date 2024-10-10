#pragma once

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_PEDAL_PAGE (ml3_pedal_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3PedalPage, ml3_pedal_page, ML3, PEDAL_PAGE, ScNavigationPage)

G_END_DECLS
