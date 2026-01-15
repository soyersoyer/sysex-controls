#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KORG_TYPE_SCENE_PAGE (korg_scene_page_get_type ())

G_DECLARE_DERIVABLE_TYPE (KorgScenePage, korg_scene_page, KORG, SCENE_PAGE, ScNavigationPage)

struct _KorgScenePageClass
{
  ScNavigationPageClass parent_class;
};

uint8_t korg_scene_page_get_scene_id (KorgScenePage *self);
gboolean korg_scene_page_get_scene_change (KorgScenePage *self);

G_END_DECLS
