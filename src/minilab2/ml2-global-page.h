#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_GLOBAL_PAGE (ml2_global_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2GlobalPage, ml2_global_page, ML2, GLOBAL_PAGE, ScNavigationPage)

G_END_DECLS
