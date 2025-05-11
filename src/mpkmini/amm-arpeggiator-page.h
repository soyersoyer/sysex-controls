#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM_TYPE_ARPEGGIATOR_PAGE (amm_arpeggiator_page_get_type ())

G_DECLARE_FINAL_TYPE (AmmArpeggiatorPage, amm_arpeggiator_page, AMM, ARPEGGIATOR_PAGE, ScNavigationPage)

G_END_DECLS
