#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

#include "ar-preset-chooser-row.h"

G_BEGIN_DECLS

#define AR_TYPE_PRESET_CHOOSER_PAGE (ar_preset_chooser_page_get_type ())

G_DECLARE_FINAL_TYPE (ArPresetChooserPage, ar_preset_chooser_page, AR, PRESET_CHOOSER_PAGE, ScNavigationPage)

typedef void (* preset_chooser_func) (ArPresetChooserRow *);

GtkWidget * ar_preset_chooser_page_new (int presets_num, int inactive_num, preset_chooser_func activate_cb);

G_END_DECLS
