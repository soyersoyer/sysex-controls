#include "dbi-controller-page.h"

struct _DbiControllerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (DbiControllerPage, dbi_controller_page, SC_TYPE_NAVIGATION_PAGE)

static void
dbi_controller_page_class_init (DbiControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/drumbruteimpact/dbi-controller-page.ui");
}

static void
dbi_controller_page_init (DbiControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
