#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define BS_TYPE_SEQUENCE_PAGE (bs_sequence_page_get_type ())

G_DECLARE_FINAL_TYPE (BsSequencePage, bs_sequence_page, BS, SEQUENCE_PAGE, ScNavigationPage)

G_END_DECLS
