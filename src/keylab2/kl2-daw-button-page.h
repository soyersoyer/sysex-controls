#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL2_TYPE_DAW_BUTTON_PAGE (kl2_daw_button_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl2DawButtonPage, kl2_daw_button_page, KL2, DAW_BUTTON_PAGE, ScNavigationPage)

G_END_DECLS
