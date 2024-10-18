#include "ml3-controller-page.h"

struct _Ml3ControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3ControllerPage, ml3_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml3_controller_page_class_init (Ml3ControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-controller-page.ui");
}

static void
ml3_controller_page_init (Ml3ControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
