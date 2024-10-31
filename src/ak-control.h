#pragma once

#include <adwaita.h>

#include "adw-bin.h"

G_BEGIN_DECLS

#define AK_TYPE_CONTROL (ak_control_get_type ())

G_DECLARE_FINAL_TYPE (AkControl, ak_control, AK, CONTROL, AdwBin)

uint32_t ak_control_get_id (AkControl *self);
int8_t ak_control_get_value_offset (AkControl *self);
uint8_t ak_control_get_size (AkControl *self);

G_END_DECLS
