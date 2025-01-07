#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MB2S_TYPE_USER_SCALE_PAGE (mb2s_user_scale_page_get_type ())

G_DECLARE_FINAL_TYPE (Mb2sUserScalePage, mb2s_user_scale_page, MB2S, USER_SCALE_PAGE, ScNavigationPage)

G_END_DECLS
