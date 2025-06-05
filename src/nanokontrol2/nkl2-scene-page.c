#include "nkl2-scene-page.h"

struct _Nkl2ScenePage
{
  KorgScenePage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nkl2ScenePage, nkl2_scene_page, KORG_TYPE_SCENE_PAGE)

static void
nkl2_scene_page_class_init (Nkl2ScenePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrol2/nkl2-scene-page.ui");
}

static void
nkl2_scene_page_init (Nkl2ScenePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
