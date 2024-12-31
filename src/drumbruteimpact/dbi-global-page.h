#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define DBI_TYPE_GLOBAL_PAGE (dbi_global_page_get_type ())

G_DECLARE_FINAL_TYPE (DbiGlobalPage, dbi_global_page, DBI, GLOBAL_PAGE, ScNavigationPage)

G_END_DECLS
