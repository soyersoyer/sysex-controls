#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MB2_TYPE_SEQUENCE_PAGE (mb2_sequence_page_get_type ())

G_DECLARE_FINAL_TYPE (Mb2SequencePage, mb2_sequence_page, MB2, SEQUENCE_PAGE, ScNavigationPage)

G_END_DECLS
