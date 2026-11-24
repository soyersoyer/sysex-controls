#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKLS_TYPE_SCENES_PAGE (nkls_scenes_page_get_type ())

G_DECLARE_FINAL_TYPE (NklsScenesPage, nkls_scenes_page, NKLS, SCENES_PAGE, ScNavigationPage)

G_END_DECLS
