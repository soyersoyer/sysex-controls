#include "ksp-cv-gate-page.h"

struct _KspCvGatePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KspCvGatePage, ksp_cv_gate_page, SC_TYPE_NAVIGATION_PAGE)

static void
ksp_cv_gate_page_class_init (KspCvGatePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keysteppro/ksp-cv-gate-page.ui");
}

static void
ksp_cv_gate_page_init (KspCvGatePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
