#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KSP_TYPE_SYNC_PAGE (ksp_sync_page_get_type ())

G_DECLARE_FINAL_TYPE (KspSyncPage, ksp_sync_page, KSP, SYNC_PAGE, ScNavigationPage)

G_END_DECLS
