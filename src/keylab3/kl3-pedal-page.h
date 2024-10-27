#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_PEDAL_PAGE (kl3_pedal_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3PedalPage, kl3_pedal_page, KL3, PEDAL_PAGE, ScNavigationPage)

G_END_DECLS
