#pragma once

#include <adwaita.h>

#include "korg-scene-page.h"

G_BEGIN_DECLS

#define NP1_TYPE_SCENE_PAGE (np1_scene_page_get_type ())

G_DECLARE_FINAL_TYPE (Np1ScenePage, np1_scene_page, NP1, SCENE_PAGE, KorgScenePage)

G_END_DECLS
