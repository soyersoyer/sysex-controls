#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKLS_TYPE_TRANSPORT_BUTTONS_PAGE (nkls_transport_buttons_page_get_type ())

G_DECLARE_FINAL_TYPE (NklsTransportButtonsPage, nkls_transport_buttons_page, NKLS, TRANSPORT_BUTTONS_PAGE, ScNavigationPage)

G_END_DECLS
