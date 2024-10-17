#include "ks32-cv-gate-page.h"

struct _Ks32CvGatePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks32CvGatePage, ks32_cv_gate_page, SC_TYPE_NAVIGATION_PAGE)

static void
ks32_cv_gate_page_class_init (Ks32CvGatePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep32/ks32-cv-gate-page.ui");
}

static void
ks32_cv_gate_page_init (Ks32CvGatePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
