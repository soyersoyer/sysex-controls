#include "ksp-touch-strip-page.h"

struct _KspTouchStripPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KspTouchStripPage, ksp_touch_strip_page, SC_TYPE_NAVIGATION_PAGE)

static void
ksp_touch_strip_page_class_init (KspTouchStripPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keysteppro/ksp-touch-strip-page.ui");
}

static void
ksp_touch_strip_page_init (KspTouchStripPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
