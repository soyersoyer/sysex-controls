#pragma once

#include <adwaita.h>

#include "korg-scene-page.h"

G_BEGIN_DECLS

#define NKLS_TYPE_SCENE_PAGE (nkls_scene_page_get_type ())

G_DECLARE_FINAL_TYPE (NklsScenePage, nkls_scene_page, NKLS, SCENE_PAGE, KorgScenePage)

G_END_DECLS
