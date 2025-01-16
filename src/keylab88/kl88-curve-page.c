#include "kl88-curve-page.h"

struct _Kl88CurvePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl88CurvePage, kl88_curve_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl88_curve_page_class_init (Kl88CurvePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab88/kl88-curve-page.ui");
}

static void
kl88_curve_page_init (Kl88CurvePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
