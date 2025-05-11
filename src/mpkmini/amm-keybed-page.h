#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM_TYPE_KEYBED_PAGE (amm_keybed_page_get_type ())

G_DECLARE_FINAL_TYPE (AmmKeybedPage, amm_keybed_page, AMM, KEYBED_PAGE, ScNavigationPage)

G_END_DECLS
