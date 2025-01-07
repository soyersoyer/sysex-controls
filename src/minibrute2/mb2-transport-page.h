#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MB2_TYPE_TRANSPORT_PAGE (mb2_transport_page_get_type ())

G_DECLARE_FINAL_TYPE (Mb2TransportPage, mb2_transport_page, MB2, TRANSPORT_PAGE, ScNavigationPage)

G_END_DECLS
