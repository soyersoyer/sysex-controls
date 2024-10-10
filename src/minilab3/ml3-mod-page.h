#pragma once

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_MOD_PAGE (ml3_mod_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3ModPage, ml3_mod_page, ML3, MOD_PAGE, ScNavigationPage)

G_END_DECLS
