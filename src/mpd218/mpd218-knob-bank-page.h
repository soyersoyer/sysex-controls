#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MPD218_TYPE_KNOB_BANK_PAGE (mpd218_knob_bank_page_get_type ())

G_DECLARE_FINAL_TYPE (Mpd218KnobBankPage, mpd218_knob_bank_page, MPD218, KNOB_BANK_PAGE, ScNavigationPage)

G_END_DECLS
