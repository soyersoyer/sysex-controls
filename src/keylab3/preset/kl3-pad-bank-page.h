#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_PAD_BANK_PAGE (kl3_pad_bank_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3PadBankPage, kl3_pad_bank_page, KL3, PAD_BANK_PAGE, ScNavigationPage)

G_END_DECLS
