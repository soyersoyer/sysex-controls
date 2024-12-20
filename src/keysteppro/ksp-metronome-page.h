#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KSP_TYPE_METRONOME_PAGE (ksp_metronome_page_get_type ())

G_DECLARE_FINAL_TYPE (KspMetronomePage, ksp_metronome_page, KSP, METRONOME_PAGE, ScNavigationPage)

G_END_DECLS
