#include "nkls-button-page.h"

struct _NklsButtonPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NklsButtonPage, nkls_button_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkls_button_page_class_init (NklsButtonPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrolstudio/nkls-button-page.ui");
}

static void
nkls_button_page_init (NklsButtonPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
