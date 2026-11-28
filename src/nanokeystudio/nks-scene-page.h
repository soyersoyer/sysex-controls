#pragma once

#include <adwaita.h>

#include "korg-scene-page.h"

G_BEGIN_DECLS

#define NKS_TYPE_SCENE_PAGE (nks_scene_page_get_type ())

G_DECLARE_FINAL_TYPE (NksScenePage, nks_scene_page, NKS, SCENE_PAGE, KorgScenePage)

G_END_DECLS
