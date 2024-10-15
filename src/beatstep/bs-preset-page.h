#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BS_TYPE_PRESET_PAGE (bs_preset_page_get_type ())

G_DECLARE_FINAL_TYPE (BsPresetPage, bs_preset_page, BS, PRESET_PAGE, ScNavigationPage)

void on_recall_activated (BsPresetPage *self, AdwActionRow* row);
void on_store_activated (BsPresetPage *self, AdwActionRow* row);

G_END_DECLS
