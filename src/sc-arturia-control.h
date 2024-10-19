#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define SC_TYPE_ARTURIA_CONTROL (sc_arturia_control_get_type ())

G_DECLARE_FINAL_TYPE (ScArturiaControl, sc_arturia_control, SC, ARTURIA_CONTROL, AdwBin)

uint32_t sc_arturia_control_get_id (ScArturiaControl *self);
gboolean sc_arturia_control_get_use_cc_offset (ScArturiaControl *self);

G_END_DECLS
