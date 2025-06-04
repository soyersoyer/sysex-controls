#pragma once

#include <adwaita.h>

#include "adw-preferences-group.h"

G_BEGIN_DECLS

#define KORG_TYPE_FIRMWARE_INFO_GROUP (korg_firmware_info_group_get_type ())

G_DECLARE_FINAL_TYPE (KorgFirmwareInfoGroup, korg_firmware_info_group, KORG, FIRMWARE_INFO_GROUP, AdwPreferencesGroup)

G_END_DECLS
