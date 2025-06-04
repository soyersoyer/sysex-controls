#include "nk2-scene-page.h"

struct _Nk2ScenePage
{
  KorgScenePage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nk2ScenePage, nk2_scene_page, KORG_TYPE_SCENE_PAGE)

static void
nk2_scene_page_class_init (Nk2ScenePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokey2/nk2-scene-page.ui");
}

static void
nk2_scene_page_init (Nk2ScenePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
