#include "bs-controller-page.h"

struct _BsControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BsControllerPage, bs_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
bs_controller_page_class_init (BsControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-controller-page.ui");
}

static void
bs_controller_page_init (BsControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
