#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_DISPLAY_BUTTON_PAGE (kl3_display_button_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3DisplayButtonPage, kl3_display_button_page, KL3, DISPLAY_BUTTON_PAGE, ScNavigationPage)

G_END_DECLS
