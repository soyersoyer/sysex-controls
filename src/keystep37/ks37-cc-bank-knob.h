#pragma once

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define KS37_TYPE_CC_BANK_KNOB (ks37_cc_bank_knob_get_type ())

G_DECLARE_FINAL_TYPE (Ks37CcBankKnob, ks37_cc_bank_knob, KS37, CC_BANK_KNOB, ScPreferencesGroup)

G_END_DECLS
