#include "microlab3-keyboard-page.h"

struct _Microlab3KeyboardPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Microlab3KeyboardPage, microlab3_keyboard_page, SC_TYPE_NAVIGATION_PAGE)

static void
microlab3_keyboard_page_class_init (Microlab3KeyboardPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/microlab3/microlab3-keyboard-page.ui");
}

static void
microlab3_keyboard_page_init (Microlab3KeyboardPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
