#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL_TYPE_AFTERTOUCH_PAGE (kl_aftertouch_page_get_type ())

G_DECLARE_FINAL_TYPE (KlAftertouchPage, kl_aftertouch_page, KL, AFTERTOUCH_PAGE, ScNavigationPage)

G_END_DECLS
