#include "nk2-button-page.h"

struct _Nk2ButtonPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nk2ButtonPage, nk2_button_page, SC_TYPE_NAVIGATION_PAGE)

static void
nk2_button_page_class_init (Nk2ButtonPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokey2/nk2-button-page.ui");
}

static void
nk2_button_page_init (Nk2ButtonPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
