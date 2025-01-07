#include "mb2-controller-page.h"

struct _Mb2ControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mb2ControllerPage, mb2_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
mb2_controller_page_class_init (Mb2ControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minibrute2/mb2-controller-page.ui");
}

static void
mb2_controller_page_init (Mb2ControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
