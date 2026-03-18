#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NK1_TYPE_BUTTON_PAGE (nk1_button_page_get_type ())

G_DECLARE_FINAL_TYPE (Nk1ButtonPage, nk1_button_page, NK1, BUTTON_PAGE, ScNavigationPage)

G_END_DECLS
