#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES3_TYPE_BUTTON_PAGE (kles3_button_page_get_type ())

G_DECLARE_FINAL_TYPE (Kles3ButtonPage, kles3_button_page, KLES3, BUTTON_PAGE, ScNavigationPage)

G_END_DECLS
