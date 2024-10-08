#pragma once

#include "sc-preferences-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_PEDAL_PAGE (ml3_pedal_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3PedalPage, ml3_pedal_page, ML3, PEDAL_PAGE, ScPreferencesPage)

G_END_DECLS
