#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MICROLAB_TYPE_PITCH_PAGE (microlab_pitch_page_get_type ())

G_DECLARE_FINAL_TYPE (MicrolabPitchPage, microlab_pitch_page, MICROLAB, PITCH_PAGE, ScNavigationPage)

G_END_DECLS
