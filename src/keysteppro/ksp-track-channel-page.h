#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KSP_TYPE_TRACK_CHANNEL_PAGE (ksp_track_channel_page_get_type ())

G_DECLARE_FINAL_TYPE (KspTrackChannelPage, ksp_track_channel_page, KSP, TRACK_CHANNEL_PAGE, ScNavigationPage)

G_END_DECLS
