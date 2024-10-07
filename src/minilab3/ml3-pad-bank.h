#pragma once

#include "sc-preferences-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_PAD_BANK (ml3_pad_bank_get_type ())

G_DECLARE_FINAL_TYPE (Ml3PadBank, ml3_pad_bank, ML3, PAD_BANK, ScPreferencesPage)

G_END_DECLS
