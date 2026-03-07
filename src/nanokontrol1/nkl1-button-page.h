#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKL1_TYPE_BUTTON_PAGE (nkl1_button_page_get_type ())

G_DECLARE_FINAL_TYPE (Nkl1ButtonPage, nkl1_button_page, NKL1, BUTTON_PAGE, ScNavigationPage)

G_END_DECLS
