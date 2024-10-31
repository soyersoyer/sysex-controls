#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM3_TYPE_KEYBED_PAGE (amm3_keybed_page_get_type ())

G_DECLARE_FINAL_TYPE (Amm3KeybedPage, amm3_keybed_page, AMM3, KEYBED_PAGE, ScNavigationPage)

G_END_DECLS
