#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MB2_TYPE_TRANSPOSITION_PAGE (mb2_transposition_page_get_type ())

G_DECLARE_FINAL_TYPE (Mb2TranspositionPage, mb2_transposition_page, MB2, TRANSPOSITION_PAGE, ScNavigationPage)

G_END_DECLS
