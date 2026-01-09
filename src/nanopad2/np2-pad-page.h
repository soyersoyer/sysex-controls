#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NP2_TYPE_PAD_PAGE (np2_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (Np2PadPage, np2_pad_page, NP2, PAD_PAGE, ScNavigationPage)

G_END_DECLS
