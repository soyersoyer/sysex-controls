#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define TL_TYPE_AFTERTOUCH_PAGE (tl_aftertouch_page_get_type ())

G_DECLARE_FINAL_TYPE (TlAftertouchPage, tl_aftertouch_page, TL, AFTERTOUCH_PAGE, ScNavigationPage)

G_END_DECLS
