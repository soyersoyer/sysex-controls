#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM2_TYPE_ARPEGGIATOR_PAGE (amm2_arpeggiator_page_get_type ())

G_DECLARE_FINAL_TYPE (Amm2ArpeggiatorPage, amm2_arpeggiator_page, AMM2, ARPEGGIATOR_PAGE, ScNavigationPage)

G_END_DECLS
