#include "nk1-button-page.h"

struct _Nk1ButtonPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nk1ButtonPage, nk1_button_page, SC_TYPE_NAVIGATION_PAGE)

static void
nk1_button_page_class_init (Nk1ButtonPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokey1/nk1-button-page.ui");
}

static void
nk1_button_page_init (Nk1ButtonPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
