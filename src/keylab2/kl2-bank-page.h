#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

#include "sc-action-row.h"

G_BEGIN_DECLS

#define KL2_TYPE_BANK_PAGE (kl2_bank_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl2BankPage, kl2_bank_page, KL2, BANK_PAGE, ScNavigationPage)

void kl2_bank_page_on_row_activated (Kl2BankPage *self, ScActionRow *row);

G_END_DECLS
