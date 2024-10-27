#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_FADER_PAGE (kl3_fader_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3FaderPage, kl3_fader_page, KL3, FADER_PAGE, ScNavigationPage)

G_END_DECLS
