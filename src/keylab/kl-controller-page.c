#include "kl-controller-page.h"

struct _KlControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KlControllerPage, kl_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl_controller_page_class_init (KlControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab/kl-controller-page.ui");
}

static void
kl_controller_page_init (KlControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
