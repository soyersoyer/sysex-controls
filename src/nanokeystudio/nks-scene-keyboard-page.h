#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKS_TYPE_SCENE_KEYBOARD_PAGE (nks_scene_keyboard_page_get_type ())

G_DECLARE_FINAL_TYPE (NksSceneKeyboardPage, nks_scene_keyboard_page, NKS, SCENE_KEYBOARD_PAGE, ScNavigationPage)

G_END_DECLS
