#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_SEA_PAGE (kl3_sea_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3SeaPage, kl3_sea_page, KL3, SEA_PAGE, ScNavigationPage)

G_END_DECLS
