#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL2_TYPE_PAD_PAGE (kl2_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl2PadPage, kl2_pad_page, KL2, PAD_PAGE, ScNavigationPage)

G_END_DECLS
