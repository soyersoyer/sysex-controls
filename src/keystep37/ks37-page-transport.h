#pragma once

#include <adwaita.h>

#include "sc-preferences-page.h"

G_BEGIN_DECLS

#define KS37_TYPE_PAGE_TRANSPORT (ks37_page_transport_get_type ())

G_DECLARE_FINAL_TYPE (Ks37PageTransport, ks37_page_transport, KS37, PAGE_TRANSPORT, ScPreferencesPage)

G_END_DECLS

