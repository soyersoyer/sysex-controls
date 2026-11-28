#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKS_TYPE_SCENES_PAGE (nks_scenes_page_get_type ())

G_DECLARE_FINAL_TYPE (NksScenesPage, nks_scenes_page, NKS, SCENES_PAGE, ScNavigationPage)

G_END_DECLS
