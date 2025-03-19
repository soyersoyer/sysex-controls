#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML_TYPE_PEDAL_PAGE (ml_pedal_page_get_type ())

G_DECLARE_FINAL_TYPE (MlPedalPage, ml_pedal_page, ML, PEDAL_PAGE, ScNavigationPage)

G_END_DECLS
