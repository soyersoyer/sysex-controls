#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NK1_TYPE_CC_MODE_PAGE (nk1_cc_mode_page_get_type ())

G_DECLARE_FINAL_TYPE (Nk1CcModePage, nk1_cc_mode_page, NK1, CC_MODE_PAGE, ScNavigationPage)

G_END_DECLS
