#include "nkl2-controller-group-page.h"

struct _Nkl2ControllerGroupPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nkl2ControllerGroupPage, nkl2_controller_group_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkl2_controller_group_page_class_init (Nkl2ControllerGroupPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrol2/nkl2-controller-group-page.ui");
}

static void
nkl2_controller_group_page_init (Nkl2ControllerGroupPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
