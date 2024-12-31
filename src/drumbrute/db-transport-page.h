#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define DB_TYPE_TRANSPORT_PAGE (db_transport_page_get_type ())

G_DECLARE_FINAL_TYPE (DbTransportPage, db_transport_page, DB, TRANSPORT_PAGE, ScNavigationPage)

G_END_DECLS
