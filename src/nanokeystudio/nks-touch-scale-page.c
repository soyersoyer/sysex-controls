#include "nks-touch-scale-page.h"

struct _NksTouchScalePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NksTouchScalePage, nks_touch_scale_page, SC_TYPE_NAVIGATION_PAGE)

static void
nks_touch_scale_page_class_init (NksTouchScalePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-touch-scale-page.ui");
}

static void
nks_touch_scale_page_init (NksTouchScalePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
