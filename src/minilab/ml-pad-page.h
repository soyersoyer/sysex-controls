#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML_TYPE_PAD_PAGE (ml_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (MlPadPage, ml_pad_page, ML, PAD_PAGE, ScNavigationPage)

G_END_DECLS
