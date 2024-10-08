#pragma once

#include "sc-preferences-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_GLOBAL_PAGE (ml3_global_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3GlobalPage, ml3_global_page, ML3, GLOBAL_PAGE, ScPreferencesPage)

G_END_DECLS
