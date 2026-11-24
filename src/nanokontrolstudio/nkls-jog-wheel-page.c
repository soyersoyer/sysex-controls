#include "nkls-jog-wheel-page.h"

struct _NklsJogWheelPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NklsJogWheelPage, nkls_jog_wheel_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkls_jog_wheel_page_class_init (NklsJogWheelPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrolstudio/nkls-jog-wheel-page.ui");
}

static void
nkls_jog_wheel_page_init (NklsJogWheelPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
