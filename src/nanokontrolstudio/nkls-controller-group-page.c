#include "nkls-controller-group-page.h"

struct _NklsControllerGroupPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NklsControllerGroupPage, nkls_controller_group_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkls_controller_group_page_class_init (NklsControllerGroupPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrolstudio/nkls-controller-group-page.ui");
}

static void
nkls_controller_group_page_init (NklsControllerGroupPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
