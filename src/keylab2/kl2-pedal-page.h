#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL2_TYPE_PEDAL_PAGE (kl2_pedal_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl2PedalPage, kl2_pedal_page, KL2, PEDAL_PAGE, ScNavigationPage)

G_END_DECLS
