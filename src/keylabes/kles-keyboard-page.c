#include "kles-keyboard-page.h"

struct _KlesKeyboardPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesKeyboardPage, kles_keyboard_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles_keyboard_page_class_init (KlesKeyboardPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-keyboard-page.ui");
}

static void
kles_keyboard_page_init (KlesKeyboardPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
