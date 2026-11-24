#pragma once

#include <adwaita.h>

#include "korg-scene-page.h"

G_BEGIN_DECLS

#define NKLS_TYPE_GLOBAL_PAGE (nkls_global_page_get_type ())

G_DECLARE_FINAL_TYPE (NklsGlobalPage, nkls_global_page, NKLS, GLOBAL_PAGE, KorgScenePage)

G_END_DECLS
