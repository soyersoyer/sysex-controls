#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES_TYPE_FADER_PAGE (kles_fader_page_get_type ())

G_DECLARE_FINAL_TYPE (KlesFaderPage, kles_fader_page, KLES, FADER_PAGE, ScNavigationPage)

G_END_DECLS
