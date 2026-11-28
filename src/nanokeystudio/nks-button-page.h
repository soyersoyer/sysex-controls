#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKS_TYPE_BUTTON_PAGE (nks_button_page_get_type ())

G_DECLARE_FINAL_TYPE (NksButtonPage, nks_button_page, NKS, BUTTON_PAGE, ScNavigationPage)

G_END_DECLS
