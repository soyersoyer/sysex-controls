#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL88_TYPE_TRANSPOSITION_PAGE (kl88_transposition_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl88TranspositionPage, kl88_transposition_page, KL88, TRANSPOSITION_PAGE, ScNavigationPage)

G_END_DECLS
