#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKS_TYPE_POWER_MANAGEMENT_BAT_PAGE (nks_power_management_bat_page_get_type ())

G_DECLARE_FINAL_TYPE (NksPowerManagementBatPage, nks_power_management_bat_page, NKS, POWER_MANAGEMENT_BAT_PAGE, ScNavigationPage)

G_END_DECLS
