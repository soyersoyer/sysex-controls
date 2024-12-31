#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define DBI_TYPE_TRANSPORT_PAGE (dbi_transport_page_get_type ())

G_DECLARE_FINAL_TYPE (DbiTransportPage, dbi_transport_page, DBI, TRANSPORT_PAGE, ScNavigationPage)

G_END_DECLS
