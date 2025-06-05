#pragma once

#include <adwaita.h>

#include "korg-scene-page.h"

G_BEGIN_DECLS

#define NKL2_TYPE_SCENE_PAGE (nkl2_scene_page_get_type ())

G_DECLARE_FINAL_TYPE (Nkl2ScenePage, nkl2_scene_page, NKL2, SCENE_PAGE, KorgScenePage)

G_END_DECLS
