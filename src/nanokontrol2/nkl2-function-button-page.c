#include "nkl2-function-button-page.h"

struct _Nkl2FunctionButtonPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nkl2FunctionButtonPage, nkl2_function_button_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkl2_function_button_page_class_init (Nkl2FunctionButtonPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrol2/nkl2-function-button-page.ui");
}

static void
nkl2_function_button_page_init (Nkl2FunctionButtonPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
