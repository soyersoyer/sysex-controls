#pragma once

#include "ks37-preferences-group.h"

G_BEGIN_DECLS

#define KS37_TYPE_PAGE_CC_BANK_KNOB (ks37_page_cc_bank_knob_get_type())

G_DECLARE_FINAL_TYPE (Ks37PageCcBankKnob, ks37_page_cc_bank_knob, KS37, PAGE_CC_BANK_KNOB, Ks37PreferencesGroup)

G_END_DECLS

