#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES_TYPE_PAD_PAGE (kles_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (KlesPadPage, kles_pad_page, KLES, PAD_PAGE, ScNavigationPage)

G_END_DECLS
