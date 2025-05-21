#include "microlab3-controller-page.h"

struct _Microlab3ControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Microlab3ControllerPage, microlab3_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
microlab3_controller_page_class_init (Microlab3ControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/microlab3/microlab3-controller-page.ui");
}

static void
microlab3_controller_page_init (Microlab3ControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
