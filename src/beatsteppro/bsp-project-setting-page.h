#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_PROJECT_SETTING_PAGE (bsp_project_setting_page_get_type ())

G_DECLARE_FINAL_TYPE (BspProjectSettingPage, bsp_project_setting_page, BSP, PROJECT_SETTING_PAGE, ScNavigationPage)

G_END_DECLS
