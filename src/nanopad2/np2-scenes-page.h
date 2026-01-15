#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NP2_TYPE_SCENES_PAGE (np2_scenes_page_get_type ())

G_DECLARE_FINAL_TYPE (Np2ScenesPage, np2_scenes_page, NP2, SCENES_PAGE, ScNavigationPage)

G_END_DECLS
