#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KS32_TYPE_SEQUENCE_PAGE (ks32_sequence_page_get_type ())

G_DECLARE_FINAL_TYPE (Ks32SequencePage, ks32_sequence_page, KS32, SEQUENCE_PAGE, ScNavigationPage)

G_END_DECLS
