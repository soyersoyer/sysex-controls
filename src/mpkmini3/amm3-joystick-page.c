#include "amm3-joystick-page.h"

struct _Amm3JoystickPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm3JoystickPage, amm3_joystick_page, SC_TYPE_NAVIGATION_PAGE)

static void
amm3_joystick_page_class_init (Amm3JoystickPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini3/amm3-joystick-page.ui");
}

static void
amm3_joystick_page_init (Amm3JoystickPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
