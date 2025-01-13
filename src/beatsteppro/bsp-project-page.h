#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_PROJECT_PAGE (bsp_project_page_get_type ())

G_DECLARE_FINAL_TYPE (BspProjectPage, bsp_project_page, BSP, PROJECT_PAGE, ScNavigationPage)

G_END_DECLS
