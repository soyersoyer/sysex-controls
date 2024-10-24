#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL2_TYPE_KFS_PAGE (kl2_kfs_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl2KfsPage, kl2_kfs_page, KL2, KFS_PAGE, ScNavigationPage)

G_END_DECLS
