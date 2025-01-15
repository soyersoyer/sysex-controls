#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_PROJECTS_PAGE (bsp_projects_page_get_type ())

G_DECLARE_FINAL_TYPE (BspProjectsPage, bsp_projects_page, BSP, PROJECTS_PAGE, ScNavigationPage)

G_END_DECLS
