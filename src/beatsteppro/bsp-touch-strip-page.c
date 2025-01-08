#include "bsp-touch-strip-page.h"

struct _BspTouchStripPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspTouchStripPage, bsp_touch_strip_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_touch_strip_page_class_init (BspTouchStripPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-touch-strip-page.ui");
}

static void
bsp_touch_strip_page_init (BspTouchStripPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
