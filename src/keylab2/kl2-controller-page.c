#include "kl2-controller-page.h"

struct _Kl2ControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2ControllerPage, kl2_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl2_controller_page_class_init (Kl2ControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-controller-page.ui");
}

static void
kl2_controller_page_init (Kl2ControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
