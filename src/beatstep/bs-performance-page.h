#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BS_TYPE_PERFORMANCE_PAGE (bs_performance_page_get_type ())

G_DECLARE_FINAL_TYPE (BsPerformancePage, bs_performance_page, BS, PERFORMANCE_PAGE, ScNavigationPage)

G_END_DECLS
