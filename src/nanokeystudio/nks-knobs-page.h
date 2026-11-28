#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKS_TYPE_KNOBS_PAGE (nks_knobs_page_get_type ())

G_DECLARE_FINAL_TYPE (NksKnobsPage, nks_knobs_page, NKS, KNOBS_PAGE, ScNavigationPage)

G_END_DECLS
