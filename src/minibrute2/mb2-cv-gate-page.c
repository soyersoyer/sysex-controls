#include "mb2-cv-gate-page.h"

struct _Mb2CvGatePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mb2CvGatePage, mb2_cv_gate_page, SC_TYPE_NAVIGATION_PAGE)

static void
mb2_cv_gate_page_class_init (Mb2CvGatePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minibrute2/mb2-cv-gate-page.ui");
}

static void
mb2_cv_gate_page_init (Mb2CvGatePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
