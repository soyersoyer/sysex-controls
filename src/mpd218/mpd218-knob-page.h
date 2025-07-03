#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MPD218_TYPE_KNOB_PAGE (mpd218_knob_page_get_type ())

G_DECLARE_FINAL_TYPE (Mpd218KnobPage, mpd218_knob_page, MPD218, KNOB_PAGE, ScNavigationPage)

G_END_DECLS
