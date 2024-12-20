#include "ksp-sync-page.h"

struct _KspSyncPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KspSyncPage, ksp_sync_page, SC_TYPE_NAVIGATION_PAGE)

static void
ksp_sync_page_class_init (KspSyncPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keysteppro/ksp-sync-page.ui");
}

static void
ksp_sync_page_init (KspSyncPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
