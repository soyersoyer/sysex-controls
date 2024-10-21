#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES3_TYPE_FADER_PAGE (kles3_fader_page_get_type ())

G_DECLARE_FINAL_TYPE (Kles3FaderPage, kles3_fader_page, KLES3, FADER_PAGE, ScNavigationPage)

G_END_DECLS
