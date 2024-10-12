#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BS_TYPE_TRANSPORT_BUTTON_PAGE (bs_transport_button_page_get_type ())

G_DECLARE_FINAL_TYPE (BsTransportButtonPage, bs_transport_button_page, BS, TRANSPORT_BUTTON_PAGE, ScNavigationPage)

G_END_DECLS
