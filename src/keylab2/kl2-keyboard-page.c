#include "kl2-keyboard-page.h"

struct _Kl2KeyboardPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2KeyboardPage, kl2_keyboard_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl2_keyboard_page_class_init (Kl2KeyboardPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-keyboard-page.ui");
}

static void
kl2_keyboard_page_init (Kl2KeyboardPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
