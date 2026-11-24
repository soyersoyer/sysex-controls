#include "nkls-controller-groups-page.h"

struct _NklsControllerGroupsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NklsControllerGroupsPage, nkls_controller_groups_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkls_controller_groups_page_class_init (NklsControllerGroupsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrolstudio/nkls-controller-groups-page.ui");
}

static void
nkls_controller_groups_page_init (NklsControllerGroupsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
