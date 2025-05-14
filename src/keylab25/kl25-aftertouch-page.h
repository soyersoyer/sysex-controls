#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL25_TYPE_AFTERTOUCH_PAGE (kl25_aftertouch_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl25AftertouchPage, kl25_aftertouch_page, KL25, AFTERTOUCH_PAGE, ScNavigationPage)

G_END_DECLS
