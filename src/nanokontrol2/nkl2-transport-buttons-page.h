#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKL2_TYPE_TRANSPORT_BUTTONS_PAGE (nkl2_transport_buttons_page_get_type ())

G_DECLARE_FINAL_TYPE (Nkl2TransportButtonsPage, nkl2_transport_buttons_page, NKL2, TRANSPORT_BUTTONS_PAGE, ScNavigationPage)

G_END_DECLS
