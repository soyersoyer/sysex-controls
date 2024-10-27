#pragma once

#include <adwaita.h>

#include "sc-action-row.h"
#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_PARTS_PAGE (kl3_parts_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3PartsPage, kl3_parts_page, KL3, PARTS_PAGE, ScNavigationPage)

void kl3_parts_page_on_part_activated (Kl3PartsPage *self, ScActionRow *row);

G_END_DECLS
