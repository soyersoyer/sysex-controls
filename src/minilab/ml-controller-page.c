#include "ml-controller-page.h"

struct _MlControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (MlControllerPage, ml_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml_controller_page_class_init (MlControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab/ml-controller-page.ui");
}

static void
ml_controller_page_init (MlControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
