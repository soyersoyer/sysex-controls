#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MB2S_TYPE_TRANSPORT_PAGE (mb2s_transport_page_get_type ())

G_DECLARE_FINAL_TYPE (Mb2sTransportPage, mb2s_transport_page, MB2S, TRANSPORT_PAGE, ScNavigationPage)

G_END_DECLS
