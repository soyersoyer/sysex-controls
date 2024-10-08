#pragma once

#include "sc-preferences-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_PAD_PAGE (ml2_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml2PadPage, ml2_pad_page, ML2, PAD_PAGE, ScPreferencesPage)

G_END_DECLS
