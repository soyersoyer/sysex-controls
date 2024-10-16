#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AR_TYPE_PRESET_PAGE (ar_preset_page_get_type ())

G_DECLARE_FINAL_TYPE (ArPresetPage, ar_preset_page, AR, PRESET_PAGE, ScNavigationPage)

void on_recall_activated (ArPresetPage *self, AdwActionRow* row);
void on_store_activated (ArPresetPage *self, AdwActionRow* row);

G_END_DECLS
