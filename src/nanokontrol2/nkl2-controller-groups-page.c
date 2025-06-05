#include "nkl2-controller-groups-page.h"

struct _Nkl2ControllerGroupsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nkl2ControllerGroupsPage, nkl2_controller_groups_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkl2_controller_groups_page_class_init (Nkl2ControllerGroupsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrol2/nkl2-controller-groups-page.ui");
}

static void
nkl2_controller_groups_page_init (Nkl2ControllerGroupsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
