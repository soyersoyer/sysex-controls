#include "ksp-launch-quantize-page.h"

struct _KspLaunchQuantizePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KspLaunchQuantizePage, ksp_launch_quantize_page, SC_TYPE_NAVIGATION_PAGE)

static void
ksp_launch_quantize_page_class_init (KspLaunchQuantizePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keysteppro/ksp-launch-quantize-page.ui");
}

static void
ksp_launch_quantize_page_init (KspLaunchQuantizePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
