#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MB2S_TYPE_SEQUENCE_PAGE (mb2s_sequence_page_get_type ())

G_DECLARE_FINAL_TYPE (Mb2sSequencePage, mb2s_sequence_page, MB2S, SEQUENCE_PAGE, ScNavigationPage)

G_END_DECLS
