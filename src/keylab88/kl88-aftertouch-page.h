#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL88_TYPE_AFTERTOUCH_PAGE (kl88_aftertouch_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl88AftertouchPage, kl88_aftertouch_page, KL88, AFTERTOUCH_PAGE, ScNavigationPage)

G_END_DECLS
