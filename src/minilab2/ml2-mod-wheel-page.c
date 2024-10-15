#include "ml2-mod-wheel-page.h"

struct _Ml2ModWheelPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2ModWheelPage, ml2_mod_wheel_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml2_mod_wheel_page_class_init (Ml2ModWheelPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-mod-wheel-page.ui");
}

static void
ml2_mod_wheel_page_init (Ml2ModWheelPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
