#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKL2_TYPE_FUNCTION_BUTTON_PAGE (nkl2_function_button_page_get_type ())

G_DECLARE_FINAL_TYPE (Nkl2FunctionButtonPage, nkl2_function_button_page, NKL2, FUNCTION_BUTTON_PAGE, ScNavigationPage)

G_END_DECLS
