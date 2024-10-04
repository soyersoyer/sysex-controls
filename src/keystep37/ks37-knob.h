#pragma once

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KS37_TYPE_KNOB (ks37_knob_get_type ())

G_DECLARE_FINAL_TYPE (Ks37Knob, ks37_knob, KS37, KNOB, ScPreferencesGroup)

G_END_DECLS
