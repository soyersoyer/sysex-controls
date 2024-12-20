#include "ksp-controller-page.h"

struct _KspControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KspControllerPage, ksp_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
ksp_controller_page_class_init (KspControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keysteppro/ksp-controller-page.ui");
}

static void
ksp_controller_page_init (KspControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
