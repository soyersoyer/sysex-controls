#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKL1_TYPE_SCENES_PAGE (nkl1_scenes_page_get_type ())

G_DECLARE_FINAL_TYPE (Nkl1ScenesPage, nkl1_scenes_page, NKL1, SCENES_PAGE, ScNavigationPage)

G_END_DECLS
