#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AMM3_TYPE_ARPEGGIATOR_PAGE (amm3_arpeggiator_page_get_type ())

G_DECLARE_FINAL_TYPE (Amm3ArpeggiatorPage, amm3_arpeggiator_page, AMM3, ARPEGGIATOR_PAGE, ScNavigationPage)

G_END_DECLS
