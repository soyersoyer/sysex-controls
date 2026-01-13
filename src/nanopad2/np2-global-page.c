#include "np2-global-page.h"

struct _Np2GlobalPage
{
  KorgScenePage parent_instance;
};

G_DEFINE_FINAL_TYPE (Np2GlobalPage, np2_global_page, KORG_TYPE_SCENE_PAGE)

static void
np2_global_page_class_init (Np2GlobalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanopad2/np2-global-page.ui");
}

static void
np2_global_page_init (Np2GlobalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
