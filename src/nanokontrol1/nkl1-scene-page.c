#include "nkl1-scene-page.h"

struct _Nkl1ScenePage
{
  KorgScenePage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nkl1ScenePage, nkl1_scene_page, KORG_TYPE_SCENE_PAGE)

static void
nkl1_scene_page_class_init (Nkl1ScenePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrol1/nkl1-scene-page.ui");
}

static void
nkl1_scene_page_init (Nkl1ScenePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
