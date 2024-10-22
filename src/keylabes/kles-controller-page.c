#include "kles-controller-page.h"

struct _KlesControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesControllerPage, kles_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles_controller_page_class_init (KlesControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-controller-page.ui");
}

static void
kles_controller_page_init (KlesControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
