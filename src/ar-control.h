#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define AR_TYPE_CONTROL (ar_control_get_type ())

G_DECLARE_FINAL_TYPE (ArControl, ar_control, AR, CONTROL, AdwBin)

uint32_t ar_control_get_id (ArControl *self);
gboolean ar_control_get_use_cc_offset (ArControl *self);

G_END_DECLS
