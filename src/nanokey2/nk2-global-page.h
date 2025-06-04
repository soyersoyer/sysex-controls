#pragma once

#include <adwaita.h>

#include "korg-scene-page.h"

G_BEGIN_DECLS

#define NK2_TYPE_GLOBAL_PAGE (nk2_global_page_get_type ())

G_DECLARE_FINAL_TYPE (Nk2GlobalPage, nk2_global_page, NK2, GLOBAL_PAGE, KorgScenePage)

G_END_DECLS
