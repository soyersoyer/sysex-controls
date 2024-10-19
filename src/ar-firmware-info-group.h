#pragma once

#include <adwaita.h>

#include "adw-preferences-group.h"

G_BEGIN_DECLS

#define AR_TYPE_FIRMWARE_INFO_GROUP (ar_firmware_info_group_get_type ())

G_DECLARE_FINAL_TYPE (ArFirmwareInfoGroup, ar_firmware_info_group, AR, FIRMWARE_INFO_GROUP, AdwPreferencesGroup)

G_END_DECLS
