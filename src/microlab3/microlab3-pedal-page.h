#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MICROLAB3_TYPE_PEDAL_PAGE (microlab3_pedal_page_get_type ())

G_DECLARE_FINAL_TYPE (Microlab3PedalPage, microlab3_pedal_page, MICROLAB3, PEDAL_PAGE, ScNavigationPage)

G_END_DECLS
