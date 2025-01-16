#include "kl88-controller-page.h"

struct _Kl88ControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl88ControllerPage, kl88_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl88_controller_page_class_init (Kl88ControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab88/kl88-controller-page.ui");
}

static void
kl88_controller_page_init (Kl88ControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
