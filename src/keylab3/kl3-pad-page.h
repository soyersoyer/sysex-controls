#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_PAD_PAGE (kl3_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3PadPage, kl3_pad_page, KL3, PAD_PAGE, ScNavigationPage)

G_END_DECLS
