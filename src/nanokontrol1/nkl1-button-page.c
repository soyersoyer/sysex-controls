#include "nkl1-button-page.h"

struct _Nkl1ButtonPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nkl1ButtonPage, nkl1_button_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkl1_button_page_class_init (Nkl1ButtonPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrol1/nkl1-button-page.ui");
}

static void
nkl1_button_page_init (Nkl1ButtonPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
