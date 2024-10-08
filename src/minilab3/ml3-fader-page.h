#pragma once

#include "sc-preferences-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_FADER_PAGE (ml3_fader_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3FaderPage, ml3_fader_page, ML3, FADER_PAGE, ScPreferencesPage)

G_END_DECLS
