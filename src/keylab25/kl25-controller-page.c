#include "kl25-controller-page.h"

struct _Kl25ControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl25ControllerPage, kl25_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl25_controller_page_class_init (Kl25ControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab25/kl25-controller-page.ui");
}

static void
kl25_controller_page_init (Kl25ControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
