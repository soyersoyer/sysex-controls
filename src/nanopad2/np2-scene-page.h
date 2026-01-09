#pragma once

#include <adwaita.h>

#include "korg-scene-page.h"

G_BEGIN_DECLS

#define NP2_TYPE_SCENE_PAGE (np2_scene_page_get_type ())

G_DECLARE_FINAL_TYPE (Np2ScenePage, np2_scene_page, NP2, SCENE_PAGE, KorgScenePage)

G_END_DECLS
