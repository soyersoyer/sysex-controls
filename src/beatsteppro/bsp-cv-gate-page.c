#include "bsp-cv-gate-page.h"

struct _BspCvGatePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspCvGatePage, bsp_cv_gate_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_cv_gate_page_class_init (BspCvGatePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-cv-gate-page.ui");
}

static void
bsp_cv_gate_page_init (BspCvGatePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
