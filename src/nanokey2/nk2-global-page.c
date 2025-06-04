#include "nk2-global-page.h"

struct _Nk2GlobalPage
{
  KorgScenePage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nk2GlobalPage, nk2_global_page, KORG_TYPE_SCENE_PAGE)

static void
nk2_global_page_class_init (Nk2GlobalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokey2/nk2-global-page.ui");
}

static void
nk2_global_page_init (Nk2GlobalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
