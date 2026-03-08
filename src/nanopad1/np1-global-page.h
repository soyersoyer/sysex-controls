#pragma once

#include <adwaita.h>

#include "korg-scene-page.h"

G_BEGIN_DECLS

#define NP1_TYPE_GLOBAL_PAGE (np1_global_page_get_type ())

G_DECLARE_FINAL_TYPE (Np1GlobalPage, np1_global_page, NP1, GLOBAL_PAGE, KorgScenePage)

G_END_DECLS
