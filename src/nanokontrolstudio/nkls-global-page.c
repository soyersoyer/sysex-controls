#include "nkls-global-page.h"

struct _NklsGlobalPage
{
  KorgScenePage parent_instance;
};

G_DEFINE_FINAL_TYPE (NklsGlobalPage, nkls_global_page, KORG_TYPE_SCENE_PAGE)

static void
nkls_global_page_class_init (NklsGlobalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrolstudio/nkls-global-page.ui");
}

static void
nkls_global_page_init (NklsGlobalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
