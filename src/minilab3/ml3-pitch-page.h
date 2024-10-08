#pragma once

#include "sc-preferences-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_PITCH_PAGE (ml3_pitch_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3PitchPage, ml3_pitch_page, ML3, PITCH_PAGE, ScPreferencesPage)

G_END_DECLS
