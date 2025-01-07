#include "mb2s-controller-page.h"

struct _Mb2sControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mb2sControllerPage, mb2s_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
mb2s_controller_page_class_init (Mb2sControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minibrute2s/mb2s-controller-page.ui");
}

static void
mb2s_controller_page_init (Mb2sControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
