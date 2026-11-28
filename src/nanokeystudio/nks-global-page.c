#include "nks-global-page.h"

struct _NksGlobalPage
{
  KorgScenePage parent_instance;
};

G_DEFINE_FINAL_TYPE (NksGlobalPage, nks_global_page, KORG_TYPE_SCENE_PAGE)

static void
nks_global_page_class_init (NksGlobalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-global-page.ui");
}

static void
nks_global_page_init (NksGlobalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
