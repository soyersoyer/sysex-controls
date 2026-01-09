#include "np2-scene-page.h"

struct _Np2ScenePage
{
  KorgScenePage parent_instance;
};

G_DEFINE_FINAL_TYPE (Np2ScenePage, np2_scene_page, KORG_TYPE_SCENE_PAGE)

static void
np2_scene_page_class_init (Np2ScenePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanopad2/np2-scene-page.ui");
}

static void
np2_scene_page_init (Np2ScenePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
