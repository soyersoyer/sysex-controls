#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES3_TYPE_PEDAL_PAGE (kles3_pedal_page_get_type ())

G_DECLARE_FINAL_TYPE (Kles3PedalPage, kles3_pedal_page, KLES3, PEDAL_PAGE, ScNavigationPage)

G_END_DECLS
