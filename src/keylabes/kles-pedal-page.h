#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES_TYPE_PEDAL_PAGE (kles_pedal_page_get_type ())

G_DECLARE_FINAL_TYPE (KlesPedalPage, kles_pedal_page, KLES, PEDAL_PAGE, ScNavigationPage)

G_END_DECLS
