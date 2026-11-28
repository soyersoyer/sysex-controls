#include "nks-touch-xy-page.h"

struct _NksTouchXyPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NksTouchXyPage, nks_touch_xy_page, SC_TYPE_NAVIGATION_PAGE)

static void
nks_touch_xy_page_class_init (NksTouchXyPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-touch-xy-page.ui");
}

static void
nks_touch_xy_page_init (NksTouchXyPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
