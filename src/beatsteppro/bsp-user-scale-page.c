#include "bsp-user-scale-page.h"

struct _BspUserScalePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspUserScalePage, bsp_user_scale_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_user_scale_page_class_init (BspUserScalePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-user-scale-page.ui");
}

static void
bsp_user_scale_page_init (BspUserScalePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
