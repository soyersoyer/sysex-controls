#include "mb2s-cv-gate-page.h"

struct _Mb2sCvGatePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mb2sCvGatePage, mb2s_cv_gate_page, SC_TYPE_NAVIGATION_PAGE)

static void
mb2s_cv_gate_page_class_init (Mb2sCvGatePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minibrute2s/mb2s-cv-gate-page.ui");
}

static void
mb2s_cv_gate_page_init (Mb2sCvGatePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
