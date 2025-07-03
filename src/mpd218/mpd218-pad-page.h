#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MPD218_TYPE_PAD_PAGE (mpd218_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (Mpd218PadPage, mpd218_pad_page, MPD218, PAD_PAGE, ScNavigationPage)

G_END_DECLS
