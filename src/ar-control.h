#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define AR_TYPE_CONTROL (ar_control_get_type ())

G_DECLARE_FINAL_TYPE (ArControl, ar_control, AR, CONTROL, AdwBin)

uint32_t ar_control_get_id (ArControl *self);
uint32_t ar_control_get_id2 (ArControl *self);
uint32_t ar_control_get_id3 (ArControl *self);
gboolean ar_control_get_use_cc_offset (ArControl *self);
double ar_control_get_multiply (ArControl *self);
uint8_t ar_control_get_maxlen (ArControl *self);
gboolean ar_control_get_write_only (ArControl *self);

G_END_DECLS
