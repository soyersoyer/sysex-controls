#include "nk1-keyboard-page.h"

struct _Nk1KeyboardPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nk1KeyboardPage, nk1_keyboard_page, SC_TYPE_NAVIGATION_PAGE)

static void
nk1_keyboard_page_class_init (Nk1KeyboardPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokey1/nk1-keyboard-page.ui");
}

static void
nk1_keyboard_page_init (Nk1KeyboardPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
