#include "nks-scene-page.h"

struct _NksScenePage
{
  KorgScenePage parent_instance;
};

G_DEFINE_FINAL_TYPE (NksScenePage, nks_scene_page, KORG_TYPE_SCENE_PAGE)

static void
nks_scene_page_class_init (NksScenePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-scene-page.ui");
}

static void
nks_scene_page_init (NksScenePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
