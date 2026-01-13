#pragma once

#include <adwaita.h>

#include "korg-scene-page.h"

G_BEGIN_DECLS

#define NP2_TYPE_GLOBAL_PAGE (np2_global_page_get_type ())

G_DECLARE_FINAL_TYPE (Np2GlobalPage, np2_global_page, NP2, GLOBAL_PAGE, KorgScenePage)

G_END_DECLS
