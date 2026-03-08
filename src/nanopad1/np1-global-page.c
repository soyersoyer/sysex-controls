#include "np1-global-page.h"

struct _Np1GlobalPage
{
  KorgScenePage parent_instance;
};

G_DEFINE_FINAL_TYPE (Np1GlobalPage, np1_global_page, KORG_TYPE_SCENE_PAGE)

static void
np1_global_page_class_init (Np1GlobalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanopad1/np1-global-page.ui");
}

static void
np1_global_page_init (Np1GlobalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
