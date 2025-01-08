#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_TRANSPOSITION_PAGE (bsp_transposition_page_get_type ())

G_DECLARE_FINAL_TYPE (BspTranspositionPage, bsp_transposition_page, BSP, TRANSPOSITION_PAGE, ScNavigationPage)

G_END_DECLS
