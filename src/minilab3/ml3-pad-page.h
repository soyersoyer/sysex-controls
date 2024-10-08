#pragma once

#include "sc-preferences-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_PAD_PAGE (ml3_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3PadPage, ml3_pad_page, ML3, PAD_PAGE, ScPreferencesPage)

G_END_DECLS
