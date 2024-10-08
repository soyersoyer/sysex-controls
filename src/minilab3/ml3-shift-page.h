#pragma once

#include "sc-preferences-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_SHIFT_PAGE (ml3_shift_page_get_type ())

G_DECLARE_FINAL_TYPE (Ml3ShiftPage, ml3_shift_page, ML3, SHIFT_PAGE, ScPreferencesPage)

G_END_DECLS
