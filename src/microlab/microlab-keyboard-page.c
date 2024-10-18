#include "microlab-keyboard-page.h"

struct _MicrolabKeyboardPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (MicrolabKeyboardPage, microlab_keyboard_page, SC_TYPE_NAVIGATION_PAGE)

static void
microlab_keyboard_page_class_init (MicrolabKeyboardPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/microlab/microlab-keyboard-page.ui");
}

static void
microlab_keyboard_page_init (MicrolabKeyboardPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
