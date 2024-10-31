#include "amm2-joystick-page.h"

struct _Amm2JoystickPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm2JoystickPage, amm2_joystick_page, SC_TYPE_NAVIGATION_PAGE)

static void
amm2_joystick_page_class_init (Amm2JoystickPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini2/amm2-joystick-page.ui");
}

static void
amm2_joystick_page_init (Amm2JoystickPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
