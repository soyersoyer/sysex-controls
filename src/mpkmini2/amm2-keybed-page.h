#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM2_TYPE_KEYBED_PAGE (amm2_keybed_page_get_type ())

G_DECLARE_FINAL_TYPE (Amm2KeybedPage, amm2_keybed_page, AMM2, KEYBED_PAGE, ScNavigationPage)

G_END_DECLS
