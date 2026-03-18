#include "nk1-scene-page.h"

struct _Nk1ScenePage
{
  KorgScenePage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nk1ScenePage, nk1_scene_page, KORG_TYPE_SCENE_PAGE)

static void
nk1_scene_page_class_init (Nk1ScenePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokey1/nk1-scene-page.ui");
}

static void
nk1_scene_page_init (Nk1ScenePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
