#include "tl-controller-page.h"

struct _TlControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (TlControllerPage, tl_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
tl_controller_page_class_init (TlControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/thelaboratory/tl-controller-page.ui");
}

static void
tl_controller_page_init (TlControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
