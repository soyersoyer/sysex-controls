#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKLS_TYPE_BUTTON_PAGE (nkls_button_page_get_type ())

G_DECLARE_FINAL_TYPE (NklsButtonPage, nkls_button_page, NKLS, BUTTON_PAGE, ScNavigationPage)

G_END_DECLS
