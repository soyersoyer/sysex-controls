#include "kles3-controller-page.h"

struct _Kles3ControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3ControllerPage, kles3_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles3_controller_page_class_init (Kles3ControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-controller-page.ui");
}

static void
kles3_controller_page_init (Kles3ControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
