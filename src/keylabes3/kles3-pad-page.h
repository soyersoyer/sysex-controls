#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES3_TYPE_PAD_PAGE (kles3_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (Kles3PadPage, kles3_pad_page, KLES3, PAD_PAGE, ScNavigationPage)

G_END_DECLS
