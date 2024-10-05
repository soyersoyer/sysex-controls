#pragma once

#include "sc-preferences-page.h"

G_BEGIN_DECLS

#define ML2_TYPE_PAD_BANK (ml2_pad_bank_get_type ())

G_DECLARE_FINAL_TYPE (Ml2PadBank, ml2_pad_bank, ML2, PAD_BANK, ScPreferencesPage)

G_END_DECLS
