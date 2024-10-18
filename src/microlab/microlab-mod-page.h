#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MICROLAB_TYPE_MOD_PAGE (microlab_mod_page_get_type ())

G_DECLARE_FINAL_TYPE (MicrolabModPage, microlab_mod_page, MICROLAB, MOD_PAGE, ScNavigationPage)

G_END_DECLS
