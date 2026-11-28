#include "nkls-scene-page.h"

struct _NklsScenePage
{
  KorgScenePage parent_instance;
};

G_DEFINE_FINAL_TYPE (NklsScenePage, nkls_scene_page, KORG_TYPE_SCENE_PAGE)

static void
nkls_scene_page_class_init (NklsScenePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrolstudio/nkls-scene-page.ui");
}

static void
nkls_scene_page_init (NklsScenePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
