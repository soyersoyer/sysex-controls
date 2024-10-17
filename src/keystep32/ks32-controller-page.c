#include "ks32-controller-page.h"

struct _Ks32ControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks32ControllerPage, ks32_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
ks32_controller_page_class_init (Ks32ControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep32/ks32-controller-page.ui");
}

static void
ks32_controller_page_init (Ks32ControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
