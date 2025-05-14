#include "kl25-curve-page.h"

struct _Kl25CurvePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl25CurvePage, kl25_curve_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl25_curve_page_class_init (Kl25CurvePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab25/kl25-curve-page.ui");
}

static void
kl25_curve_page_init (Kl25CurvePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
