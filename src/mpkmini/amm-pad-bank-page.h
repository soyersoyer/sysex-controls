#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM_TYPE_PAD_BANK_PAGE (amm_pad_bank_page_get_type ())

G_DECLARE_FINAL_TYPE (AmmPadBankPage, amm_pad_bank_page, AMM, PAD_BANK_PAGE, ScNavigationPage)

G_END_DECLS
