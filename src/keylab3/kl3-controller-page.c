#include "kl3-controller-page.h"

struct _Kl3ControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3ControllerPage, kl3_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_controller_page_class_init (Kl3ControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-controller-page.ui");
}

static void
kl3_controller_page_init (Kl3ControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
