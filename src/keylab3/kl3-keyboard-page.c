#include "kl3-keyboard-page.h"

struct _Kl3KeyboardPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3KeyboardPage, kl3_keyboard_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_keyboard_page_class_init (Kl3KeyboardPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-keyboard-page.ui");
}

static void
kl3_keyboard_page_init (Kl3KeyboardPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
