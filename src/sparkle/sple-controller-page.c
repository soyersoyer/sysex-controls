#include "sple-controller-page.h"

struct _SpleControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (SpleControllerPage, sple_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
sple_controller_page_class_init (SpleControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/sparkle/sple-controller-page.ui");
}

static void
sple_controller_page_init (SpleControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
