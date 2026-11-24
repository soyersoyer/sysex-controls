#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKLS_TYPE_POWER_MANAGEMENT_BAT_PAGE (nkls_power_management_bat_page_get_type ())

G_DECLARE_FINAL_TYPE (NklsPowerManagementBatPage, nkls_power_management_bat_page, NKLS, POWER_MANAGEMENT_BAT_PAGE, ScNavigationPage)

G_END_DECLS
