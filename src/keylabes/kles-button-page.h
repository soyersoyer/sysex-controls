#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES_TYPE_BUTTON_PAGE (kles_button_page_get_type ())

G_DECLARE_FINAL_TYPE (KlesButtonPage, kles_button_page, KLES, BUTTON_PAGE, ScNavigationPage)

G_END_DECLS
