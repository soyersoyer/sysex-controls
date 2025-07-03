#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MPD218_TYPE_PAD_BANK_PAGE (mpd218_pad_bank_page_get_type ())

G_DECLARE_FINAL_TYPE (Mpd218PadBankPage, mpd218_pad_bank_page, MPD218, PAD_BANK_PAGE, ScNavigationPage)

G_END_DECLS
