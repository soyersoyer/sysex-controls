#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NP1_TYPE_SCENES_PAGE (np1_scenes_page_get_type ())

G_DECLARE_FINAL_TYPE (Np1ScenesPage, np1_scenes_page, NP1, SCENES_PAGE, ScNavigationPage)

G_END_DECLS
