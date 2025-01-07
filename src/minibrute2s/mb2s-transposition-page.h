#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MB2S_TYPE_TRANSPOSITION_PAGE (mb2s_transposition_page_get_type ())

G_DECLARE_FINAL_TYPE (Mb2sTranspositionPage, mb2s_transposition_page, MB2S, TRANSPOSITION_PAGE, ScNavigationPage)

G_END_DECLS
