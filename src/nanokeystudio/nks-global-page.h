#pragma once

#include <adwaita.h>

#include "korg-scene-page.h"

G_BEGIN_DECLS

#define NKS_TYPE_GLOBAL_PAGE (nks_global_page_get_type ())

G_DECLARE_FINAL_TYPE (NksGlobalPage, nks_global_page, NKS, GLOBAL_PAGE, KorgScenePage)

G_END_DECLS
