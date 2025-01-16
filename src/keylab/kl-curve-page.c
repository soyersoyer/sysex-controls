#include "kl-curve-page.h"

struct _KlCurvePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KlCurvePage, kl_curve_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl_curve_page_class_init (KlCurvePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab/kl-curve-page.ui");
}

static void
kl_curve_page_init (KlCurvePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
