#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_SYNC_PAGE (bsp_sync_page_get_type ())

G_DECLARE_FINAL_TYPE (BspSyncPage, bsp_sync_page, BSP, SYNC_PAGE, ScNavigationPage)

G_END_DECLS
