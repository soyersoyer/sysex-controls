#include "bs-performance-page.h"

struct _BsPerformancePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BsPerformancePage, bs_performance_page, SC_TYPE_NAVIGATION_PAGE)

static void
bs_performance_page_class_init (BsPerformancePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-performance-page.ui");
}

static void
bs_performance_page_init (BsPerformancePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
