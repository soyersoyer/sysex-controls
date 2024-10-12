#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BS_TYPE_PAD_PAGE (bs_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (BsPadPage, bs_pad_page, BS, PAD_PAGE, ScNavigationPage)

G_END_DECLS
