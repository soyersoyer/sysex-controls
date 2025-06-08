#pragma once

#include <adwaita.h>

#include "adw-preferences-group.h"

G_BEGIN_DECLS

#define AR_TYPE_PRESET_GROUP (ar_preset_group_get_type ())

G_DECLARE_FINAL_TYPE (ArPresetGroup, ar_preset_group, AR, PRESET_GROUP, AdwPreferencesGroup)

uint8_t ar_preset_group_get_presets_num (ArPresetGroup *self);
uint8_t ar_preset_group_get_readonly_num (ArPresetGroup *self);

void ar_preset_group_on_recall_activated (ArPresetGroup *self, AdwActionRow* row);
void ar_preset_group_on_store_activated (ArPresetGroup *self, AdwActionRow* row);

G_END_DECLS
