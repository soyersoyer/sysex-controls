#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BSP_TYPE_SEQUENCER_PAGE (bsp_sequencer_page_get_type ())

G_DECLARE_FINAL_TYPE (BspSequencerPage, bsp_sequencer_page, BSP, SEQUENCER_PAGE, ScNavigationPage)

G_END_DECLS
