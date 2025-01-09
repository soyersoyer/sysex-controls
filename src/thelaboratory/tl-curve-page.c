#include "tl-curve-page.h"

struct _TlCurvePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (TlCurvePage, tl_curve_page, SC_TYPE_NAVIGATION_PAGE)

static void
tl_curve_page_class_init (TlCurvePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/thelaboratory/tl-curve-page.ui");
}

static void
tl_curve_page_init (TlCurvePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
