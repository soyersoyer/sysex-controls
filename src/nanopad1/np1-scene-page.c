#include "np1-scene-page.h"

struct _Np1ScenePage
{
  KorgScenePage parent_instance;
};

G_DEFINE_FINAL_TYPE (Np1ScenePage, np1_scene_page, KORG_TYPE_SCENE_PAGE)

static void
np1_scene_page_class_init (Np1ScenePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanopad1/np1-scene-page.ui");
}

static void
np1_scene_page_init (Np1ScenePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
