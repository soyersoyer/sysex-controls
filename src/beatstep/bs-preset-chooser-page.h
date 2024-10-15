#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"
#include "bs-preset-chooser-row.h"
#include "bs-preset-page.h"

G_BEGIN_DECLS

#define BS_TYPE_PRESET_CHOOSER_PAGE (bs_preset_chooser_page_get_type ())

G_DECLARE_FINAL_TYPE (BsPresetChooserPage, bs_preset_chooser_page, BS, PRESET_CHOOSER_PAGE, ScNavigationPage)

typedef void (* preset_chooser_func) (BsPresetPage *, BsPresetChooserRow *);

GtkWidget * bs_preset_chooser_page_new (int presets_num, preset_chooser_func activate_cb, BsPresetPage *preset_page);

G_END_DECLS
