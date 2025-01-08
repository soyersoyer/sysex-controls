#include "bsp-sync-page.h"

struct _BspSyncPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspSyncPage, bsp_sync_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_sync_page_class_init (BspSyncPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-sync-page.ui");
}

static void
bsp_sync_page_init (BspSyncPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
