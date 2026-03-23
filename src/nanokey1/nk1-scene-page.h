#pragma once

#include <adwaita.h>

#include "korg-scene-page.h"

G_BEGIN_DECLS

#define NK1_TYPE_SCENE_PAGE (nk1_scene_page_get_type ())

G_DECLARE_FINAL_TYPE (Nk1ScenePage, nk1_scene_page, NK1, SCENE_PAGE, KorgScenePage)

G_END_DECLS
