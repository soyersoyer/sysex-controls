#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_TRANSPORT_PAGE (bsp_transport_page_get_type ())

G_DECLARE_FINAL_TYPE (BspTransportPage, bsp_transport_page, BSP, TRANSPORT_PAGE, ScNavigationPage)

G_END_DECLS
