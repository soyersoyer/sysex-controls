#include "nk2-keyboard-page.h"

struct _Nk2KeyboardPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nk2KeyboardPage, nk2_keyboard_page, SC_TYPE_NAVIGATION_PAGE)

static void
nk2_keyboard_page_class_init (Nk2KeyboardPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokey2/nk2-keyboard-page.ui");
}

static void
nk2_keyboard_page_init (Nk2KeyboardPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
