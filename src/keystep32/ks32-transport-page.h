#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KS32_TYPE_TRANSPORT_PAGE (ks32_transport_page_get_type ())

G_DECLARE_FINAL_TYPE (Ks32TransportPage, ks32_transport_page, KS32, TRANSPORT_PAGE, ScNavigationPage)

G_END_DECLS
