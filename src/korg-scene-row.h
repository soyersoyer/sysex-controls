#pragma once

#include <adwaita.h>

#include "adw-action-row.h"
#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KORG_TYPE_SCENE_ROW (korg_scene_row_get_type ())

G_DECLARE_FINAL_TYPE (KorgSceneRow, korg_scene_row, KORG, SCENE_ROW, AdwActionRow)

uint8_t korg_scene_row_get_scene_id (KorgSceneRow *self);
gboolean korg_scene_row_get_scene_change (KorgSceneRow *self);
GType korg_scene_row_get_target_page (KorgSceneRow *self);

void korg_scene_nav_push (KorgSceneRow *row, ScNavigationPage *page);

G_END_DECLS
