#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKL2_TYPE_BUTTON_PAGE (nkl2_button_page_get_type ())

G_DECLARE_FINAL_TYPE (Nkl2ButtonPage, nkl2_button_page, NKL2, BUTTON_PAGE, ScNavigationPage)

G_END_DECLS
