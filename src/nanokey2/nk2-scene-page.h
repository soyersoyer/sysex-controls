#pragma once

#include <adwaita.h>

#include "korg-scene-page.h"

G_BEGIN_DECLS

#define NK2_TYPE_SCENE_PAGE (nk2_scene_page_get_type ())

G_DECLARE_FINAL_TYPE (Nk2ScenePage, nk2_scene_page, NK2, SCENE_PAGE, KorgScenePage)

G_END_DECLS
