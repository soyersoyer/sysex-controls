#pragma once

#include <adwaita.h>

#include "adw-bin.h"

G_BEGIN_DECLS

#define MM_TYPE_CONTROL (mm_control_get_type ())

G_DECLARE_FINAL_TYPE (MmControl, mm_control, MM, CONTROL, AdwBin)

uint32_t mm_control_get_id (MmControl *self);
gboolean mm_control_get_use_cc_offset (MmControl *self);
int8_t mm_control_get_value_offset (MmControl *self);
uint8_t mm_control_get_size (MmControl *self);
uint8_t mm_control_get_mask (MmControl *self);
double mm_control_get_multiply (MmControl *self);


G_END_DECLS
