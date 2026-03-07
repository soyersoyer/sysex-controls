#pragma once

#include <adwaita.h>

#include "korg-scene-page.h"

G_BEGIN_DECLS

#define NKL1_TYPE_SCENE_PAGE (nkl1_scene_page_get_type ())

G_DECLARE_FINAL_TYPE (Nkl1ScenePage, nkl1_scene_page, NKL1, SCENE_PAGE, KorgScenePage)

G_END_DECLS
